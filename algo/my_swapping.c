void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
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
