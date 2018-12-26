#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], int size, int key)
{
    int low = 0, high = size-1, mid;
    //mid = low + (high - low)/2;

    while (low <= high)
    {
	mid = low + (high - low)/2;

	if (arr[mid] == key)
	{
	    printf("Found!\n");
	    return mid;
	}
	else if (arr[mid] >= key)
	{
	    high = mid - 1;
	}
	else
	    low = mid +1;
    
    }
    return -1;
}

int main()
{
    int *arr,size,key,index,i;

    printf("Enter the number of elements\n");
    scanf("%d", &size);
    arr = (int *) malloc (sizeof(int) * size);

    printf("Enter the elements in sorted order\n");
    for (i=0;i<size;i++)
    {
	scanf("%d", &arr[i]);
    }
    printf("Enter the Key to search\n");
    scanf("%d", &key);

    index = binary_search(arr,size,key);
    if (index == -1)
	printf("Element not found!\n");
    else
	printf("Found at: %d\n", index);


}
