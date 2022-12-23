#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define skiplist_max 6

typedef struct snode {
    int key;
    /// @brief 
    int val;
    struct snode **nextnode;
} snode;

typedef struct skiplist {
    int floor;
    struct snode *head;
} skiplist;

skiplist *skiplist_init(skiplist *list) {
    int i;
    snode *head = (snode *) malloc(sizeof(struct snode));
    list->head = head;
    head->key = INT_MAX;
    head->nextnode = (snode **) malloc(
            sizeof(snode*) * (skiplist_max + 1));
    for (i = 0; i <= skiplist_max; i++) {
        head->nextnode[i] = list->head;
    }

    list->floor = 1;

    return list;
}

static int random() {
    int floor = 1;
    while (rand() < RAND_MAX / 2 && floor < skiplist_max)
        floor++;
    return floor;
}

int insert(skiplist *list, int key, int val) {
    snode *update[skiplist_max + 1];
    snode *x = list->head;
    int i, floor;
    for (i = list->floor; i >= 1; i--) {
        while (x->nextnode[i]->key < key)
            x = x->nextnode[i];
        update[i] = x;
    }
    x = x->nextnode[1];

    if (key == x->key) {
        x->val = val;
        return 0;
    } else {
        floor = random();
        if (floor > list->floor) {
            for (i = list->floor + 1; i <= floor; i++) {
                update[i] = list->head;
            }
            list->floor = floor;
        }

        x = (snode *) malloc(sizeof(snode));
        x->key = key;
        x->val = val;
        x->nextnode = (snode **) malloc(sizeof(snode*) * (floor + 1));
        for (i = 1; i <= floor; i++) {
            x->nextnode[i] = update[i]->nextnode[i];
            update[i]->nextnode[i] = x;
        }
    }
    return 0;
}

snode *search(skiplist *list, int key) {
    snode *x = list->head;
    int i;
    for (i = list->floor; i >= 1; i--) {
        while (x->nextnode[i]->key < key)
            x = x->nextnode[i];
    }
    if (x->nextnode[1]->key == key) {
        return x->nextnode[1];
    } else {
        return NULL;
    }
    return NULL;
}

static void free_node(snode *x) {
    if (x) {
        free(x->nextnode);
        free(x);
    }
}

int delete(skiplist *list, int key) {
    int i;
    snode *update[skiplist_max + 1];
    snode *x = list->head;
    for (i = list->floor; i >= 1; i--) {
        while (x->nextnode[i]->key < key)
            x = x->nextnode[i];
        update[i] = x;
    }

    x = x->nextnode[1];
    if (x->key == key) {
        for (i = 1; i <= list->floor; i++) {
            if (update[i]->nextnode[i] != x)
                break;
            update[i]->nextnode[i] = x->nextnode[i];
        }
        free_node(x);

        while (list->floor > 1 && list->head->nextnode[list->floor]
                == list->head)
            list->floor--;
        return 0;
    }
    return 1;
}

void free(skiplist *list)
{
    snode *current_node = list->head->nextnode[1];
    while(current_node != list->head) {
        snode *next_node = current_node->nextnode[1];
        free(current_node->nextnode);
        free(current_node);
        current_node = next_node;
    }
    free(current_node->nextnode);
    free(current_node);
    free(list);
}

static void dump(skiplist *list) {
    snode *x = list->head;
    while (x && x->nextnode[1] != list->head) {
        printf("%d[%d]->", x->nextnode[1]->key, x->nextnode[1]->val);
        x = x->nextnode[1];
    }
    printf("NIL\n");
}

int main() {
    int arr[] = { 8,7,11,1,3,6,9}, i;
    skiplist * list;
    list = (skiplist *)malloc(sizeof(skiplist));
    skiplist_init(list);

    printf("Insert:--------------------\n");
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        insert(list, arr[i], arr[i]);
    }
    dump(list);

    printf("Search:--------------------\n");
    int keys[] = { 3, 4, 7, 10, 111 };

    for (i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        snode *x = search(list, keys[i]);
        if (x) {
            printf("key = %d, val = %d\n", keys[i], x->val);
        } else {
            printf("key = %d, not fuound\n", keys[i]);
        }
    }

    printf("Search:--------------------\n");
    delete(list, 1);
    delete(list, 11);
    dump(list);
    free(list);

    return 0;
}
