#include <stdio.h>

void Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void BubbleSort(int A[], int n)
{
	int flag; //Used to indicate whether swapping has occurred
	int temp;

	for(int i=0; i < n-1; i++) //This loop is for the number of Parses
	{
		flag = 0; //Initially set to 0 at the beginning of each Parse

		//This loop is for the number of comparisons that need to be made in each Parse and i is subtracted from n-1 as well.
		//This is due to there being 1 less comparison each Parse due to 1 more element being sorted at the end of each Parse.
		for(int j=0; j < n-1-i; j++) 
		{
			if(A[j] > A[j+1])
			{
				Swap(&A[j], &A[j+1]);

				flag = 1; //swapping has occurred
			}
		}

		if(flag == 0) //No swapping has occurred, therefore the list must already be Sorted
			break;
	}
}

void Display(int A[], int n)
{
	for(int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	int A[] = {3,5,7,1};
	int n = 4;

	BubbleSort(A, n);

	Display(A, n);

	return 0;
}