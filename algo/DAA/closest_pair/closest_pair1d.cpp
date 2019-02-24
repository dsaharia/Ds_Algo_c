#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;
void mergeSort(int *, int, int);
void merge(int *, int, int, int);

int main()
{
	int *points, size = 6;

	points = new int[6];
	cout << "---Closest Pair problem for a Line---" << endl;
	cout << "Enter the x-coordinates of points" << endl;

	for(int i=0;i<6;i++)
	{
		cin >> points[i];
	}
	mergeSort(points, 0, size-1);
	closestPair(points);
	// cout << "after merge sort" << endl;
	// for(int i=0;i<6;i++)
	// {
	// 	cout << points[i] << endl;
	// }

}

void mergeSort(int *points, int l, int r)
{
	int mid;
	if (l < r)
	{
		mid = (l + r) / 2;
		mergeSort(points, l, mid);
		mergeSort(points, mid+1, r);
		merge(points, l, mid, r);
	}

}

void merge(int *points, int l, int mid, int r)
{
	int i, j, k;
	int nl, nr;

	nl = mid - l + 1;
	nr = r - mid;

	int *left, *right;
	left = new int[nl];
	right = new int[nr];

	for (int i = 0; i < nl; i++)
	{
		left[i] = points[i+l];
	}
	for (int i = 0; i < nr; i++)
	{
		right[i] = points[i + mid + 1];
	}
	i=0; // for first subarray
	j=0; // for second subarray
	k=l; // for merged subarray

	while (i < nl && j < nr)
	{
		if (left[i] <= right[j])
		{
			points[k] = left[i++];
		}
		else
		{
			points[k] = right[j++];
		}
		k++; // to increment the merged array

	}
	while (i < nl)
	{
		points[k++] = left[i++];
	}

	while (j < nr)
	{
		points[k++] = right[j++];
	}
}

int distance(int a, int b)
{
	int d;
	d = abs(b-a);
}

int closestPair(int *points, int size)
{
	int *left, *right;
	left = new int[size/2];
	right = new int[size/2];
	transferElements(points, left, right, size);
	if (size == 2)
	{
		return distance(points[0], points[1]);
	}

	else
	{
		closestPair(left, size/2);
		closestPair(right, size/2);
		across_closestPair(left, right)
	}

}

void transferElements(int *points, int *left, int *right, int size)
{
	for (int i = 0; i < (size/2); ++i)
	{
		left[i] = points[i];
	}
	for (; i < size; ++i)
	{
		right[i] = points[i];
	}
}

void across_closestPair(int *left, int * right)
{
	int 
}