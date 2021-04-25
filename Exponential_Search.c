#include<stdio.h>

int exponential_search(int array[], int length, int item);
int binary_search(int array[], int start, int stop, int item);
int main()
{
	printf("How many array elements in the array:- ");
	int length;
	scanf("%d", &length);

	int array[50];
	for (int i = 0; i < length; i++)
	{
		printf("Element No %d is:- ", i + 1);
		scanf("%d", &array[i]);
	}

	int item;
	printf("Enter The item to be searched:- ");
	scanf("%d", &item);

	int position;
	position = exponential_search(array, length, item);
	if (position == -1)
	{
		printf("Element is not in the array.");
	}
	else
	{
		printf("Element is present at the index %d in the array.", position);
	}
}

int exponential_search(int array[], int length, int item)
{
	for (int i = 0; i < length; i += 2)
	{
		if (array[i] == item)
		{
			return i;
		}
		else if (array[i] > item)
		{
			int stop = i, start = i / 2;
			return (binary_search(array, start, stop, item));
		}
	}
}

int binary_search(int array[], int start, int stop, int item)
{
	int mid = 0;
	while (start < stop)
	{
		mid = (start + stop) / 2;
		if (array[mid] == item)
		{
			return mid;
		}
		if (item < array[mid])
		{
			stop = mid - 1;
		}
		if (item > array[mid])
		{
			start = mid + 1;
		}
	}
	return -1;
}
