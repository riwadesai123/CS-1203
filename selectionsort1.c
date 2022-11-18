#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}


void sort(int array[], int size) {
  for (int jump = 0; jump < size - 1; jump++) {
    int min = jump;
    for (int i = jump + 1; i < size; i++) {

      
      if (array[i] < array[min])
        min = i;
    }

    
    swap(&array[min], &array[jump]);
  }
}


void printarray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// driver code
int main() {
  int array[] = {20, 12, 10, 15, 2};
  int size = sizeof(array) / sizeof(array[0]);
  sort(array, size);
  printf("Sorted array :  \n");
  printarray(array, size);
}
