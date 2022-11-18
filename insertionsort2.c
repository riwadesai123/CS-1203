#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int value;
    struct node* nextnode;
};
 
struct node* head = NULL;
struct node* insertsort = NULL;
 
void new(int val)
{
    
    struct node* newnode
        = (struct node*)malloc(sizeof(struct node));
    newnode->value = val;
    
    newnode->nextnode = head;
    
    head = newnode;
}
void sortinsert(struct node* newnode)
{
    
    if (insertsort == NULL || insertsort->value >= newnode->value) {
        newnode->nextnode = insertsort;
        insertsort = newnode;
    }
    else {
        struct node* current = insertsort;
        
        while (current->nextnode != NULL
               && current->nextnode->value < newnode->value) {
            current = current->nextnode;
        }
        newnode->nextnode = current->nextnode;
        current->nextnode = newnode;
    }
}
 

void insertionsort()
{
 
    struct node* current = head;
 
    
    while (current != NULL) {
 
        
        struct node* nextnode = current->nextnode;
 
        
        sortinsert(current);
 
        
        current = nextnode;
    }
    
    head = insertsort;
}
 

void print(struct node* head)
{
    while (head != NULL) {
        printf("%d->", head->value);
        head = head->nextnode;
    }
    printf("NULL");
}
 

int main()
{
 
    new(2);
    new(61);
    new(14);
    new(36);
    new(99);
 
    printf("linked list:\n");
    print(head);
    printf("\n");
    insertionsort(head);
    printf("sorted list: \n");
    print(head);
}
