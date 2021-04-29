#include<stdio.h>
#include<stdbool.h>

int fibonacci_search(int array[], int length, int item);
int get_last_fibonacci_number(int n);

int main()
{
	printf("\n-:Array Elements Must be sorted in ASSCENDING order:-\n\n");
	int length;
	printf("Enter the number of array elements:- ");
	scanf("%d", &length);

	int array[50];
	for (int i = 0; i < length; i++)
	{
		printf("Element no %d is:- ",i+1);
		scanf("%d", &array[i]);
	}

	int item;
	printf("Enteer the element to be searched:- ");
	scanf("%d", &item);

	int position;
	position = fibonacci_search(array, length, item);
	position == -1 ? printf("\n\nElement not found.") : printf("\n\nElement is present at index %d in the array.",position);
}

int fibonacci_search(int array[], int length, int item)
{
	int low = 0;
	int high = length - 1;
	int loc = -1;
	int flag = 0;
	int index = 0;
	int temp_len = length;
	int count = 1;
	while (flag!=1 && low<=high)
	{
		printf("\n\nIteration Number:- %d ------\n",count);
		printf("low --> %d\nhigh --> %d",low,high);
		count++;
		// get the F(m-2) th fibonacci number -------
		index = get_last_fibonacci_number(temp_len);
		if (item==array[index+low])
		{
			flag = 1;
			loc = low + index;
			break;
		}

		if (item>array[index+low])
		{
			low = low + index + 1;
		}

		if (item<array[index+low])
		{
			high = low + index - 1;
		}
		// adjust the length of the array ------
		temp_len = high - low + 1;
	}
	return loc;
}

int get_last_fibonacci_number(int n)
{
	// initialising fibonacci numbers ---------
	int fibm2 = 0;	// (m-2)'th fibonacci number.
	int fibm1 = 1;	// (m-1)'th fibonacci number.
	int fibm = fibm2 + fibm1;	// m'th fibonacci number.

	if (n==0 || n==1)
	{
		return 0;
	}
	/* fibm is going to store the smallest fibonacci
	   number greater than or equal to the length of the array.*/
	while (fibm < n)
	{
		fibm2 = fibm1;
		fibm1 = fibm;
		fibm = fibm2 + fibm1;
	}
	return fibm2;
}
