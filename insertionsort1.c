#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x, i, j, tmp;
    int arr[50];
    printf("enter number of elements\n");
    scanf("%d", &x);
    printf("enter %d integers\n", x);
    for (i = 0; i < x; i++) 
    {
        scanf("%d", &arr[i]);
    }
    for (i = 1; i < x; i++) 
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) 
        {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
    printf("sorted list :\n");
    for (i = 0; i < x; i++) 
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
