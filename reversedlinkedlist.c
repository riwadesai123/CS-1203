#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int value;                        //value of node
    struct node *nextnode;           //Address of the next node
}*head;

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
void reverse_list()
{
    struct node *new_head, *currentnode;
 
    if(head != NULL)
    {
        new_head = head;
        currentnode = head->nextnode;
        head = head->nextnode;
 
        new_head->nextnode = NULL; //convert the first node as last
 
        while(head != NULL)
        {
            head = head->nextnode;
            currentnode->nextnode = new_head;
 
            new_head = currentnode;
            currentnode = head;
        }
        head = new_head; //convert the last node as head
    }
}
int main()
{
    int n;
		
		
    printf(" enter no. of nodes : ");
    scanf("%d", &n);
    createNodeList(n);
    printf("\n Data entered in the list : \n");
    displayList();
    reverse_list();
    printf("\n reversed lis: \n");
    displayList();
    return 0;
}

