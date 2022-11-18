#include <stdio.h>
#include <stdlib.h>


void swap(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}


int partition(int array[], int lesser, int greater) {
  
  int pivot = array[greater];
  
  int i = (lesser - 1);


  for (int j = lesser; j < greater; j++) {
    if (array[j] <= pivot) {
        
      i++;
      
      
      swap(&array[i], &array[j]);
    }
  }

 
  swap(&array[i + 1], &array[greater]);
  

  return (i + 1);
}

void quickSort(int array[], int lesser, int greater) {
  if (lesser < greater) {
    

    int pi = partition(array, lesser, greater);
    
    
    quickSort(array, lesser, pi - 1);
    
 
    quickSort(array, pi + 1, greater);
  }
}


void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

struct Node {
    int value;
    struct Node* nextnode;
};
 

void new(struct Node** head, int value)
{
    
    struct Node* node
        = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("error, invalid\n");
    }
    else {
        node->value = value;
        node->nextnode = NULL;
        if (*head == NULL) {
            *head = node;
        }
        else {
            struct Node* tmp = *head;
 
            
            while (tmp->nextnode != NULL) {
                tmp = tmp->nextnode;
            }
 
            
            tmp->nextnode = node;
        }
    }
}
 

void display(struct Node* head)
{
    if (head == NULL) {
        printf("Empty linked list");
        return;
    }
    struct Node* tmp = head;
    printf("\n Linked List :");
    while (tmp != NULL) {
        printf("  %d", tmp->value);
        tmp = tmp->nextnode;
    }
}
 
struct Node* endnode(struct Node* head)
{
    struct Node* tmp = head;
    while (tmp != NULL && tmp->nextnode != NULL) {
        tmp = tmp->nextnode;
    }
    return tmp;
}
 

struct Node* parition1(struct Node* begin, struct Node* end)
{
    // Get begin node of given linked list
    struct Node* pivot = begin;
    struct Node* start = begin;
    int tmp = 0;
    while (start != NULL && start != end) {
        if (start->value < end->value) {
            pivot = begin;
 
            // Swapping  node values
            tmp = begin->value;
            begin->value = start->value;
            start->value = tmp;
 
            // Visiting the nextnode node
            begin = begin->nextnode;
        }
 
        // Visiting the nextnode node
        start = start->nextnode;
    }
 
    // Change end node value to current node
    tmp = begin->value;
    begin->value = end->value;
    end->value = tmp;
    return pivot;
}
 
// Performing quick sort in  the given linked list
void quicksort1(struct Node* begin, struct Node* end)
{
    if (begin == end) {
        return;
    }
    struct Node* pivot = parition1(begin, end);
 
    if (pivot != NULL && pivot->nextnode != NULL) {
        quicksort1(pivot->nextnode, end);
    }
 
    if (pivot != NULL && begin != pivot) {
        quicksort1(begin, pivot);
    }
}

int main() {
  int data[] = {8, 7, 2, 1, 0, 9, 6};
  
  int n = sizeof(data) / sizeof(data[0]);
  
  printf("unsorted array\n");
  printArray(data, n);
  
 
  quickSort(data, 0, n - 1);
  
  printf("sorted array : \n");
  printArray(data, n);

  struct Node* head = NULL;
 
   
    new(&head, 4);
    new(&head, 53);
    new(&head, 17);
    new(&head, 92);
    new(&head, 42);
    new(&head, 37);
    new(&head, 64);
    new(&head, 81);
    new(&head, 9);
    new(&head, 1);
    printf("\n Before Sort ");
    display(head);
 
   
    quicksort1(head, endnode(head));
    printf("\n After Sort ");
    display(head);
}

