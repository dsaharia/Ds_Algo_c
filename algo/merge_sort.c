#include <stdio.h>
#include <stdlib.h>
#include "my_swapping.c"

void merge(int arr[], int l, int m, int r)
{


}

void merge_sort(int arr[], int l, int r)
{
    

}



int main()
{
    int *arr, size, i;

    printf("Enter the number of elements\n");
    scanf("%d", &size);

    arr = (int *) malloc(sizeof(int) * size);
    if (arr == NULL)
    {
	printf("Memory block cannot be allocated\n");
	return 0;
    }

    printf("Enter the elements\n");
    for(i=0;i<size;i++)
    {
	scanf("%d", &arr[i]);
    }
    merge_sort(arr, 0, size-1);
    printf("--- Merge sort --- \nElements in sorted order\n");
    print(arr,size);

}
