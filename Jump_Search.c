#include <stdio.h>
#include <math.h>

int linear_search(int array[], int start, int stop, int item);
int jump_search(int array[], int length, int item);
int main()
{
	printf("How many elements are in the array:- ");
	int length;
	scanf("%d",&length);

	int array[length];
	for (int i = 0; i < length; ++i)
	{
		printf("Element No %d is:- ",i+1);
		scanf("%d",&array[i]);
	}

	int item;
	printf("Enter the item to search:- ");
	scanf("%d",&item);

	int position;
	position=jump_search(array,length,item);
	if (position==-1)
		printf("Element is not present in the array.");
	else
		printf("Element is present at the index %d in the array.",position);
}

int linear_search(int array[], int start, int stop, int item)
{
	for (int i = start; i < stop; ++i)
	{
		if (array[i]==item)
		{
			return i;
		}
	}
	return -1;
}

int jump_search(int array[], int length, int item)
{
	int block;
	block=(int)sqrt(length);
	int start=0,stop=0;
	for (int i = 0; i < length; i+=block)
	{
		if (array[i]==item)
		{
			return i;
		}
		else if (array[i]>item)
		{
			stop=i;
			start=i-block;
			return (linear_search(array,start,stop,item));
		}
	}
	return -1;
}