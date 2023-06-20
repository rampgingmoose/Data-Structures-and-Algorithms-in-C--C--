#include <stdlib.h>
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

void InsertionSort(int A[], int n)
{
	int j, x;

	for(int i=1; i<n; i++)
	{
		j = i-1;
		x = A[i];
		while(j > -1 && A[j] > x)
		{
			A[j+1] = A[j];
			j--;
		}

		A[j+1] = x;
	}
}

void SelectionSort(int A[], int n)
{
	int k;
	for(int i=0; i < n-1; i++) //This loop is for passes, i doesn't need to go to the last element as the last elements will have been sorted already.
	{
		for(int j=k=i; j<n; j++) //Handles the logic within each pass, j & k start from i as everything before i is already sorted.
		{
			if(A[j] < A[k]) //If the element at j is less than k then bring k to j 
				k = j;
		}
		Swap(&A[i], &A[k]); //k should be at the smallest element so swap k's element with i's element
	}
}

/**
 * \brief Partitions a list of elements for Quick Sort
 * \param l first indexed element
 * \param h highest indexed element
 */
int Partition(int A[], int l, int h)
{
	int pivot = A[l];
	int i = l, j =h;

	do
	{
		do{i++;}while(A[i]<=pivot);
		do{j--;}while(A[j]>pivot);
		if(i<j)
		{
			Swap(&A[i], &A[j]);
		}
	}while(i<j);

	Swap(&A[l], &A[j]);
	return j;
}

void QuickSort(int A[], int l, int h)
{
	int j;

	if(l<h) //ensures there are at least two elements in the list
	{
		j = Partition(A,l,h);
		QuickSort(A,l,j); //j acts as the max int in this list
		QuickSort(A,j+1,h);
	}
}

void Merge(int A[], int l, int mid, int h)
{
	int i=l, j = mid+1, k = l; //l==low, h==high
	int B[100]; //sets the auxiliary array's size to that of the original array

	while(i<=mid && j<=h)
	{
		if(A[i]<A[j])
			B[k++]=A[i++];
		else
			B[k++]=A[j++];
	}

	//Copies any left over elements from the array to auxiliary array
	for(; i<=mid; i++)
		B[k++] = A[i];
	for(; j<=h; j++)
		B[k++] = A[j];

	//Copies all elements from the auxiliary array to the original array
	for(i=l; i<=h; i++)
		A[i] = B[i];
}

/**
 * \ n is for number of elements in the list.
 */
void IterativeMergeSort(int A[], int n)
{
	int p, i, l, mid, h; //l==low, h==high

	//This loop is for passes and we need logn passes. So p is representative of list sizes
	for(p=2; p<=n; p=p*2) 
	{
		for(i=0; i+p-1<n; i=i+p) //i+p moves i by p amount, so if p==2 i will move 2 index places and if p==4 i will move 4
		{
			l=i;
			h = i+p-1;
			mid=(l+h)/2;
			Merge(A,l,mid,h);
		}
		if(n-i>p/2)
		{
			l=i;
			h=i+p-1;
			mid = (l+h)/2;
			Merge(A, l, mid, n-1);
		}
	}

	//This statement is for lists that have an odd number of elements. If the list is odd or not in powers of 2 there will
	//leftover elements. This logic will handle merging the leftover elements and will require one extra pass.
	if(p/2 < n)
		Merge(A,0,p/2-1, n-1); 
}

/**
 * l==low and h==high
 */
void RecursiveMergeSort(int A[], int l, int h)
{
	int mid;

	if(l<h)
	{
		mid=(l+h)/2;
		RecursiveMergeSort(A,l,mid); //Left side of the list
		RecursiveMergeSort(A,mid+1,h); //Right side of the list
		Merge(A,l,mid,h);
	}
}

int FindMaxElement(int A[], int n)
{
	int max = A[0];
	for(int i = 1; i<n-1; i++)
	{
		if(A[i]>max)
			max = A[i];
	}

	return max;
}

void CountSort(int A[], int n)
{
	int max = FindMaxElement(A, n);
	//We want the size of max to be 1 greater than that of the largest element in A so that element index
	//is available to us in Count
	int *Count = (int *)malloc((max+1) * sizeof(int));
	int i,j;
	
	for(i=0; i<max+1; i++)
		Count[i] = 0;
	for(i=0; i<n; i++)
		Count[A[i]]++;
	
	i=0;j=0;
	while(i<max+1)
	{
		if(Count[i]>0)
		{
			A[j++] = i;
			Count[i]--;
		}
		else
			i++;
	}
}

void ShellSort(int A[], int n)
{
	int i,j,gap,temp;

	for(gap=n/2; gap>=1; gap/=2)
	{
		for(i=gap; i<n; i++)
		{
			temp = A[i];
			j = i-gap;
			while(j>=0 && A[j]>temp)
			{
				A[j+gap]=A[j];
				j-=gap;
			}
			A[j+gap] = temp;
		}
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
	int A[] = {11,13,7,12,16,9,24,5,10,3};
	int n = 10;

	ShellSort(A, n);

	Display(A, n);

	return 0;
}