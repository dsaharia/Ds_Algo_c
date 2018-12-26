#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[],int size)
{
    int i, j, box;

    for(j=1;j<size;j++)
    {
	box = arr[j];
	i = j - 1;

	while (i >= 0 && arr[i] > box)
	{
	    arr[i+1] = arr[i];
	    i = i - 1;
	    
	}
	arr[i+1] = box;
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
    for(i=0;i<size;i++)
    {
	scanf("%d", &arr[i]);
    }
    insertion_sort(arr, size);
    printf("--- Insertion Sort --- \nElements in sorted order\n");
    print(arr,size);

}
