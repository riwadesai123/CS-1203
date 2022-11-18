#include<stdio.h>
#include<stdlib.h>

struct Node {
    int value;
    struct Node* nextnode;
};
struct Node* new(int a)
{
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->value = a;
    tmp->nextnode = NULL;
    return tmp;
}
struct Node* selectionsort(struct Node* head)
{
    struct Node *i, *j, *k, *m, *n;
    i = j = head;
    while (j->nextnode) {
        k = m = j->nextnode;
        while (m) {
            if (j->value > m->value) {
                if (j->nextnode == m) {
                    if (j == head) {
                        j->nextnode = m->nextnode;
                        m->nextnode = j;
                        n = j;
                        j = m;
                        m = n;
                        k = m;
                        head = j;
                        m = m->nextnode;
                    }
                    else {
                        j->nextnode = m->nextnode;
                        m->nextnode = j;
                        i->nextnode = m;
                        n = j;
                        j = m;
                        m = n;
                        k = m;
                        m = m->nextnode;
                    }
                }
                else {
                    if (j == head) {
                        n = j->nextnode;
                        j->nextnode = m->nextnode;
                        m->nextnode = n;
                        k->nextnode = j;
                        n = j;
                        j = m;
                        m = n;
                        k = m;
                        m = m->nextnode;
                        head = j;
                    }
                    else {
                        n = j->nextnode;
                        j->nextnode = m->nextnode;
                        m->nextnode = n;
                        k->nextnode = j;
                        i->nextnode = m;
                        n = j;
                        j = m;
                        m = n;
                        k = m;
                        m = m->nextnode;
                    }
                }
            }
            else {
                k = m;
                m = m->nextnode;
            }
        }
        i = j;
        j = j->nextnode;
    }
    
    return head;
}
void print(struct Node* head)
{
    while (head) {
        printf("%d->",head->value);
        head = head->nextnode;
    }
}
int main()
{
   struct Node* head = new(9);
    head->nextnode = new(70);
    head->nextnode->nextnode = new(68);
    head->nextnode->nextnode->nextnode = new(35);
    printf("linked list:\n");
    print(head);
    printf("\n");
    printf("sorted list: \n");
    head = selectionsort(head);
    print(head);
    return 0;
}
