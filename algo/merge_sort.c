#include <stdio.h>
#include <stdlib.h>
#include "my_swapping.c"

void merge(int arr[], int l, int mid, int r)
{
    int i,j,k;
    int nl = mid - l +1; // no of elements in left subarray.
    int nr = r - mid;  // no of elements in right subarray.
    int al[nl], ar[nr]; // declare the temp arrays.
    for (i=0; i<nl; i++)
    {
	al[i] = arr[l+i];
    }

    for (j=0;j<nr;j++)
    {
	ar[j] = arr[mid+1+j];
    }
    i=j=0; // for tracking first and second subarray elements.
    k=l; // tracking the emrged array.

    while(i<nl && j<nr)
    {
	if (al[i] <= ar[j])
	{
	    arr[k] = al[i];
	    i++;
	}
	else
	{
	    arr[k] = ar[j];
	    j++;
	}
	k++;
    
    }
    // If one sub array finishes first
    while (i<nl)
    {
	arr[k] = al[i];
	i++;
	k++;
    }
    while (j<nr)
    {
	arr[k] = ar[j];
	j++;
	k++;
    
    }
}

void mergeSort(int arr[], int l, int r)
{
    int mid;

    if (l < r)
    {
	mid = l + (r - l)/2;

	mergeSort(arr, l, mid);
	mergeSort(arr, mid+1, r);
	merge(arr, l, mid, r);
    
    }

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
    mergeSort(arr, 0, size-1);
    printf("--- Merge sort --- \nElements in sorted order\n");
    print(arr,size);

}
