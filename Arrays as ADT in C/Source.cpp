#include <cstdlib>
#include <stdio.h>

using namespace std;

struct Array
{
	int *A;
	int size;
	int length;
};

void Display(struct Array arr)
{
	printf("\nElements are: ");
	for(int i = 0; i < arr.length; i++)
	{
		printf("%d ", arr.A[i]);
	}
	printf("\n");
}

void Append(struct Array *arr, int x)
{
	int index;

	if(arr-> length < arr->size)
	{
		arr->A[arr->length++] = x;
	}
}

void Insert(struct Array *arr, int index, int x)
{
	if(index >= 0 && index <= arr-> length)
	{
		for(int i = arr->length; i > index; i--)
		{
			arr->A[i] = arr->A[i-1];
		}

		arr->A[index] = x;
		arr->length++;
	}
}

int Delete(struct Array *arr, int index)
{
	int x = 0;

	if(index >= 0 && index < arr->length)
	{
		x = arr->A[index];
		for(int i = index; i < arr->length; i++)
		{
			arr->A[i] = arr->A[i+1];
		}
		arr->length--;
		return x;
	}

	return 0; //index is invalid
}

int LinearSearch(struct Array arr, int key)
{
	for(int i = 0; i < arr.length; i++)
	{
		if(key == arr.A[i])
		{
			return i;
		}
	}

	return -1;
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int TranspositionLinearSearch(struct Array *arr, int key)
{
	for(int i = 0; i < arr->length; i++)
	{
		if(key == arr->A[i])
		{
			swap(&arr->A[i], &arr->A[i-1]);
			return i-1;
		}
	}

	return -1;
}

int MoveToFrontLinearSearch(struct Array *arr, int key)
{
	for(int i = 0; i < arr-> length; i++)
	{
		if(key == arr->A[i])
		{
			swap(&arr->A[i], &arr->A[0]);
			return 0;
		}
	}

	return -1;
}

int BinarySearch(struct Array arr, int low, int high, int key)
{
	int mid;

	while(low <= high)
	{
		mid = (low+high)/2;

		if(key == arr.A[mid])
			return mid;
		else if(key < arr.A[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1; //search is unsuccessful
}

int RecursiveBinarySearch(struct Array arr, int low, int high, int key)
{
	int mid;

	if(low <= high)
	{
		mid = (low + high) / 2;

		if(key == arr.A[mid])
			return mid;
		else if (key < arr.A[mid])
			return RecursiveBinarySearch(arr, low, mid-1, key);
		else
			return RecursiveBinarySearch(arr, mid + 1, high, key);
	}

	return -1;
}

int Get(struct Array arr, int index)
{
	if(index >= 0 && index <= arr.length)
	{
		return arr.A[index];
	}
}

void Set(struct Array *arr, int index, int x)
{
	if(index >= 0 && index <= arr->length)
	{
		arr->A[index] = x;
	}
}

int Max(struct Array arr)
{
	int max = arr.A[0];

	for(int i = 1; i < arr.length; i++)
	{
		if(arr.A[i] > max)
		{
			max = arr.A[i];
		}
	}

	return max;
}

int Min(struct Array arr)
{
	int min = arr.A[0];

	for(int i = 0; i < arr.length; i++)
	{
		if(arr.A[i] < min)
		{
			min = arr.A[i];
		}
	}

	return min;
}

int Sum(struct Array arr)
{
	int Total = 0;

	for(int i = 0; i < arr.length; i++)
	{
		Total += arr.A[i];	
	}

	return Total;
}

int RecursiveSum(struct Array arr, int n)
{
	int Total = 0;
	
	if(n < 0)
		return 0;
	else
		return RecursiveSum(arr, n-1) + arr.A[n];
}

int Average(struct Array arr)
{
	int Total = 0;

	for(int i = 0; i < arr.length; i++)
	{
		Total += arr.A[i];
	}

	return Total / arr.length;
}

void ReverseArray(struct Array *arr)
{
	int *B;
	int i, j;

	B = (int *)malloc(arr->length*sizeof(int));

	for(i = arr->length-1, j = 0; i >= 0; i--, j++)
	{
		B[j] = arr->A[i];
	}
	for(i = 0; i < arr->length; i++)
	{
		arr->A[i] = B[i];
	}

	free(B);
}

void ReverseArrayUsingSwap(struct Array *arr)
{
	int i, j;

	for(i = 0, j = arr->length-1; i < j; i++, j--)
	{
		swap(&arr->A[i], &arr->A[j]);
	}
}

void LeftShitArray(struct Array *arr)
{
	for(int i = 0; i < arr->length-1; i++)
	{
		arr->A[i] = arr->A[i + 1];
	}

	arr->A[arr->length-1] = 0;
}

void LeftRotateArray(struct Array *arr)
{
	int temp = arr->A[0];

	for(int i = 0; i < arr->length-1; i++)
	{
		arr->A[i] = arr->A[i+1];
	}
	arr->A[arr->length-1] = temp;
}

void InsertIntoSortedArray(struct Array *arr, int key)
{
	int i = arr->length-1;

	while(arr->A[i] > key)
	{
		arr->A[i+1] = arr->A[i];
		i--;
	}

	arr->A[i+1] = key;
	arr->length++;
}

bool isArraySorted(struct Array arr)
{
	for(int i = 0; i < arr.length-1; i++)
	{
		if(arr.A[i] > arr.A[i+1])
			return false; //returns 0
	}

	return true; //returns 1
}

void ArrangeNegativeAndPositiveNumbers(struct Array *arr)
{
	int i = 0;
	int j = arr->length-1;

	while(i < j)
	{
		while(arr->A[i] < 0) {i++;}
		while(arr->A[j] >= 0) {j--;}

		if(i<j)
		{
			swap(&arr->A[i], &arr->A[j]);
		}
	}
}

struct Array* MergeArrays(struct Array *arr1, struct Array *arr2)
{
	int i =0,j = 0,k = 0;
	struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
	int m = arr1->length;
	int n = arr2->length;

	while(i < m && j < n)
	{
		if(arr1->A[i] < arr2->A[j])
		{
			arr3->A[k++] = arr1->A[i++];
		}
		else
		{
			arr3->A[k++] = arr2->A[j++];
		}
	}

	for(; i < m; i++)
	{
		arr3->A[k++] = arr1->A[i];
	}
	for(; j < n; j++)
	{
		arr3->A[k++] = arr2->A[j++];
	}
	arr3->length = arr1->length + arr2->length;
	arr3->size = 10;
	return arr3;
}

/**
 Adds elements from arr1 and arr2 but only adds any repeating/common elements once
 */
struct Array* SortedArrayUnion(struct Array *arr1, struct Array *arr2)
{
	int i =0, j=0, k=0;
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
	int m = arr1->length;
	int n = arr2->length;

	while(i < m && j < n)
	{
		if(arr1->A[i] < arr2->A[j])
		{
			arr3->A[k++] = arr1->A[i++];
		}
		else if(arr2->A[j] < arr1->A[i])
		{
			arr3->A[k++] = arr2->A[j++];
		}
		else
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}

	for(; i<m; i++)
	{
		arr3->A[k++] = arr1->A[i];
	}
	for(; j<n; j++)
	{
		arr3->A[k++] = arr2->A[j];
	}

	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

/**
 * Copies all of array 1 to array 3, array 2 then loops through all values of array 1. If there are equal the loop break, if the
 * search reaches the end of the first array with no matches to the element of the current index of the second array, then add
 * that element from the 2nd array to the 3rd.
 */
struct Array* UnsortedArrayUnion(struct Array *arr1, struct Array *arr2)
{
	int i=0, j=0, k=0;
	struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));
	int m = arr1->length;
	int n = arr2->length;

	for(i; i < m; i++)
	{
		arr3->A[k++] = arr1->A[i];
	}

	for (j = 0; j < n; j++)
	{
		for(i = 0; i < m; i++)
		{
			if(arr2->A[j] == arr1->A[i])
				break;
		}

		if(i == arr1->length)
		{
			arr3->A[k++] = arr2->A[j];
		}
	}

	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

/**
Only adds elements to the third array that exist in both array 1 and array 2
 */
struct Array* SortedArrayIntersection(struct Array *arr1, struct Array *arr2)
{
	int i=0, j=0, k=0;
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
	int m = arr1->length;
	int n = arr2->length;

	while(i < m && j < n)
	{
		if(arr1->A[i] < arr2->A[j])
			i++;
		else if(arr2->A[j] < arr1->A[i])
			j++;
		else
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}

	arr3->length = k;
	arr3->size = 10;

	return arr3;
}

/**
 * Only adds elements to arr3 that only exist in arr1 so any elements that arr1 shares with arr2 will be ignored
 */
struct Array* ArrayDifference(struct Array *arr1, struct Array *arr2)
{
	int i = 0, j = 0, k = 0;
	struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));

	int m = arr1->length;
	int n = arr2->length;

	while(i < m && j < n)
	{
		if(arr1->A[i] < arr2->A[j])
		{
			arr3->A[k++] = arr1->A[i++];
		}
		else if(arr2->A[j] < arr1->A[i])
		{
			j++;
		}
		else
		{
			i++;
			j++;
		}
	}

	for(; i < m; i++)
	{
		arr3->A[k++] = arr1->A[i];
	}

	arr3->length = k;
	arr3->size = 10;

	return arr3;
}

int main()
{
	struct Array arr1;
	int choice;
	int index;
	int x;

	printf("Enter the size of the Array: ");
	scanf_s("%d", &arr1.size);
	arr1.A = (int *)malloc(arr1.size*sizeof(int));
	arr1.length = 0;

	do
	{
		printf("Menu\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Sum\n");
		printf("5. Display\n");
		printf("6. Exit\n");

		printf("Enter your selection: ");
		scanf_s("%d", &choice);

		switch(choice)
		{
			case 1: printf("Enter an element and index: ");
				scanf_s("%d%d", &x, &index);
				Insert(&arr1,index, x);
				break;
			case 2: printf("Enter index: ");
				scanf_s("%d", &index);
				x = Delete(&arr1, index);
				printf("Element that was Deleted: %d\n", x);
				break;
			case 3: printf("eneter element to search: ");
				scanf_s("%d", &x);
				index = LinearSearch(arr1, x);
				printf("Element is at index: %d\n", index);
				break;
			case 4: printf("Sum is: %d\n", Sum(arr1));
				break;
			case 5: Display(arr1);
		}
	}while(choice < 6);

	return 0;
}