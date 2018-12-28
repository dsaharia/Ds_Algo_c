#include <stdio.h>
#include <stdlib.h>
#include "my_swapping.c"


void bubble_sort(int arr[], int size) 
{
    int k,i,flag;

    for(k=0;k < size; k++)
    {
	flag = 0;
	for(i=0;i<size-k-1;i++)
	{
	    if(arr[i] > arr[i+1])
	    {
		swap(&arr[i],&arr[i+1]);
		flag = 1;
	    }
	
	}
    //flag becomes 1 only when swapping takes place meaning array is not sorted.
    if (flag == 0)
	break;
    }
}



void print(int arr[], int size)
{
    int i;
    for (i=0;i<size;i++)
    {
	printf("%d  ", arr[i]);
    }
    printf("\n");
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
    bubble_sort(arr, size);
    printf("--- Bubble Sort --- \nElements in sorted order\n");
    print(arr,size);

}
