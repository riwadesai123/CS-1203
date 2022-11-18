#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int value;                        //value of node
    struct node *nextnode;           //Address of the next node
}*head;

struct node* newnode(int x)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = x;
    newNode->nextnode = NULL;
    return newNode;
}
void createNodeList(int x) 
{
    struct node *prev, *tmp;
    int value, n;
    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL) 
    {
        printf("data cannot be alloted");
    }
    else
    {


        printf(" enter data for node 1 : ");
        scanf("%d", &value);
        head->value = value;      
        head->nextnode = NULL; 
        tmp = head;

        for(n=2; n<=x; n++)
        {
            prev = (struct node *)malloc(sizeof(struct node));
            if(prev == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" enter data for node %d : ", n);
                scanf(" %d", &value);
 
                prev->value = value;      
                prev->nextnode = NULL; 
                tmp->nextnode = prev; 
                tmp = tmp->nextnode; 
            }
        }
    }
} 
int lengthOfLinkedList(struct node* head) {
    int length = 0;
    while(head != NULL) {
        ++length;
        head = head->nextnode;
    }
    return length;
}
struct node* chunkrevese(int k) {
    if(head == NULL||head->nextnode == NULL) return head;
    
    int length = lengthOfLinkedList(head);
    
    struct node* tmp = newnode(0);
    tmp->nextnode = head;
    
    struct node* prev = tmp;
    struct node* currentnode;
    struct node* next;
    
    while(length >= k) {
        currentnode = prev->nextnode;
        next = currentnode->nextnode;
        for(int i=1;i<k;i++) {
            currentnode->nextnode = next->nextnode;
            next->nextnode = prev->nextnode;
            prev->nextnode = next;
            next = currentnode->nextnode;
        }
        prev = currentnode;
        length -= k;
    }
    return tmp->nextnode;
}
void displayList()
{
    struct node *tmp;
    if(head == NULL)
    {
        printf("empty list");
    }
    else
    {
        tmp = head;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->value);       
            tmp = tmp->nextnode;                     
        }
    }
}         

int main()
{
    int n,k;
		
		
    printf(" enter no. of nodes : ");
    scanf("%d", &n);
    createNodeList(n);
    printf("\n Data entered in the list : \n");
    displayList();
    printf("\n enter chunk value: \n");
    scanf("%d", &k);
    chunkrevese(k);
    displayList();
    return 0;
}




