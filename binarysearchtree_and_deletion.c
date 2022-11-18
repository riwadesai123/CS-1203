#include <stdio.h>
#include <stdlib.h>

    struct node
    {
        int value; 
        struct node *rightnode; 
        struct node *leftnode; 
    };

   
    struct node* nextnode(int n)
    {
        struct node *tmp;
        tmp = malloc(sizeof(struct node));
        tmp->value = n;
        tmp->rightnode = NULL;
        tmp->leftnode = NULL;
        

        return tmp;
    }

   
    struct node* find(struct node *parent, int n)
    {
        if(parent==NULL || parent->value==n)
            return parent;
        else if(n>parent->value) 
            return find(parent->rightnode, n);
        else 
            return find(parent->leftnode,n);
    }

    // insertion
    struct node* insert(struct node *parent, int n)
    {
        //finding for the place to insert
        if(parent==NULL)
            return nextnode(n);
        else if(n>parent->value) // n is greater. Should be inserted to the right
            parent->rightnode = insert(parent->rightnode, n);
        else // n is smaller and should be inserted to left
            parent->leftnode = insert(parent->leftnode,n);
        return parent;
    }

   struct node* find_minimum(struct node* node)
{
    struct node* current = node;
 
   
    while (current->leftnode != NULL) {
        current = current->leftnode;
    }
    return (current->value);
}

    
    struct node* delete(struct node *parent, int n)
    {
        //finding for the item to be deleted
        if(parent==NULL)
            return NULL;
        if (n>parent->value)
            parent->rightnode = delete(parent->rightnode, n);
        else if(n<parent->value)
            parent->leftnode = delete(parent->leftnode, n);
        else
        {
           
            if(parent->leftnode==NULL && parent->rightnode==NULL)
            {
                free(parent);
                return NULL;
            }

            
            else if(parent->leftnode==NULL || parent->rightnode==NULL)
            {
                struct node *tmp;
                if(parent->leftnode==NULL)
                    tmp = parent->rightnode;
                else
                    tmp = parent->leftnode;
                free(parent);
                return tmp;
            }

            
            else
            {
                struct node *tmp = find_minimum(parent->rightnode);
                parent->value = tmp->value;
                parent->rightnode = delete(parent->rightnode, tmp->value);
            }
        }
        return parent;
    }

   
    void inorder(struct node *parent)
    {
        if(parent!=NULL) 
        {
            inorder(parent->leftnode); 
            printf(" %d ", parent->value); 
            inorder(parent->rightnode);
        }
    }

    int main()
    {
        struct node *parent;
        parent = nextnode(25);
        insert(parent,1);
        insert(parent,6);
        insert(parent,9);
        insert(parent,7);
        insert(parent,5);
        insert(parent,79);
        insert(parent,55);
        insert(parent,41);
        insert(parent,39);
        insert(parent, 98);
        insert(parent, 69);

        inorder(parent);
        printf("\n");

        parent = delete(parent, 69);

        parent = delete(parent, 41);

        parent = delete(parent, 5);

        parent = delete(parent, 98);

        inorder(parent);
        printf("\n");

        return 0;
    }
    
