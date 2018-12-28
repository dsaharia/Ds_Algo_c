#include <stdio.h>
#include <stdlib.h>


int bsearch_recursive(int arr[], int l, int h, int key)
{
    int mid;

    if (l > h)
	return -1;

    
	mid = l + (h-l)/2;

	if (arr[mid] == key )
	    return mid;
	else if (arr[mid] > key)
	    return bsearch_recursive(arr, l, mid-1, key);
	else
	    return bsearch_recursive(arr, mid+1, h, key);

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

    index = bsearch_recursive(arr, 0, size-1, key);
    if (index == -1)
	printf("Element not found!\n");
    else
	printf("Found at: %d\n", index);

}
