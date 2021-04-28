#include<stdio.h>

int binary_search_recur(int array[], int lower, int upper, int item);
int main()
{
	int length;
	printf("\n\n-:Array must be sorted in ASSCENDING order:-\n\n");
	printf("Enter the array length:- ");
	scanf("%d",&length);

	int array[50];
	for (int i = 0; i < length; i++)
	{
		printf("Element number %d is:- ",i+1);
		scanf("%d",&array[i]);
	}

	int item;
	printf("Enter the element to be searched:- ");
	scanf("%d",&item);

	int position;
	position = binary_search_recur(array, 0, length, item);
	if (position==-1)
	{
		printf("Element is not present in array.");
	}
	else
	{
		printf("Element is present at index %d in the array.", position);
	}
}

int binary_search_recur(int array[], int lower, int upper, int item)
{
	int begin = lower, end = upper-1;
	int mid = 0;
	while (begin<=end)
	{
		mid = (begin + end) / 2;
		if (array[mid]==item)
		{
			return mid;
		}

		if (item>array[mid])
		{
			return binary_search_recur(array, mid + 1, upper, item);
		}

		if (item<array[mid])
		{
			return binary_search_recur(array,lower,mid,item);
		}
	}
	return -1;
}
