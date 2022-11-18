#include<stdio.h>
#include<stdlib.h>
 

void heapify(int* array, int n, int i)
{
    
    int root = i;
 
    int leftchild = 2 * i + 1;
    int rightchild  = 2 * i + 2;
 
    if (leftchild < n && array[leftchild] > array[root])
    {
        root = leftchild;
    }
 
    if (rightchild < n && array[rightchild] > array[root])
    {
        root = rightchild;
    }
 
    if (root != i)
    {
        int tmp = array[i];
        array[i] = array[root];
        array[root] = tmp;
 

        heapify(array, n, root);
    }
}
void heapsort(int* array, int n)
{
   
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(array, n, i);
    }
 
    
    for (int i = n - 1; i >= 0; i--)
    {
        
        int tmp = array[i];
        array[i] = array[0];
        array[0] = tmp;
 
      
        heapify(array, i, 0);
    }
}
 
void print_array(int* array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", array[i]);
    }
}
 
int main()
{
    int array[] = { 1, 63, 15, 93, 2, 45, 55, 99, 78, 69 };
    int n = sizeof(array) / sizeof(array[0]);
 
    printf("\n array before sorting:\n");
    print_array(array, n);
 
    heapsort(array, n);
 
    printf("\n array after sorting:\n");
    print_array(array, n);
 
    return 0;
}
 




 

