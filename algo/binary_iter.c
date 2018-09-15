#include <stdio.h>

int bin_search(int*,int,int);
main()
{
    int a[] = {2,5,7,8,15,19,24,26,66};
    int size = 9,key,index=0,i=0;
    printf("--Binary Search Iterative--\n");
    printf("Array is:\n");
    for(i=0;i<size;i++)
    {
	printf("%d  ",a[i]);
    }
    printf("\n");
    printf("Enter the key to search:\n");
    scanf("%d", &key);

    index = bin_search(a,size,key);
    if(index != -1)
	printf("Elememt %d is at index %d\n",key,index);
    else if (index == -1)
	printf("Element Not Found!\n");

}

int bin_search(int a[],int size,int key)
{
    int l=0,h=size,mid=0;
    while(l <= h)
    {
	mid = l + (h-l)/2; //To avoid overflow
	
	if(key == a[mid])
	{
	    return mid;
	}
	else if (key < a[mid])
	{
	    h = mid -1;
	}
	else if (key > a[mid])
	{
	    l = mid + 1;
	}
    }
    return -1;

}
