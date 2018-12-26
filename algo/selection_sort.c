#include <stdio.h>
#include <stdlib.h>

void selection_sort(int arr[], int size)
{
    int i, j, temp, minId;
    for (i = 0; i < size; i++)
    {
        minId = i;
        for (j = i+1; j < size; j++)
        {
            if (arr[j] < arr[minId])
            {
                minId = j;
            }
        }
        temp = arr[minId];
        arr[minId] = arr[i];
        arr[i] = temp;
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
    selection_sort(arr, size);
    printf("--- Selection Sort --- \nElements in sorted order\n");
    print(arr,size);

}
