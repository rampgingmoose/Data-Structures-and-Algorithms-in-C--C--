#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

class Array
{
private:
	int *A;
	int size;
	int length;

	void Swap(int *x, int *y);

public:
	Array()
	{
		size = 10;
		length = 0;
		A= new int[size];
	}
	Array(int sz)
	{
		size = sz;
		length = 0;
		A = new int [size];
	}
	void Display();
	void Append(int x);
	void Insert(int index, int x);
	int LinearSearch(int key);
	int TranspositionLinearSearch(int key);
	int MoveToFrontLinearSearch(int key);
	int BinarySearchLoop(int key);
	int RecursiveBinarySearch(int low, int high, int key);
	int DeleteIndex(int index);
	int Get(int index);
	void Set(int index, int x);
	int Max();
	int Min();
	int Sum();
	float Average();
	void ReverseArrayWithAuxiliaryArray();
	void ReverseArrayWithSwap();
	void LeftShiftArray();
	void LeftRotateArray();
	void InsertIntoSortedArray(int key);
	bool isArraySorted();
	void ArrangePositiveAndNegatives();
	Array* MergeArrays(Array arr2);
	Array* Union(Array arr2);
	Array* Intersection(Array arr2);
	Array* Difference(Array arr2);

	~Array()
	{
		delete [] A;
	}
};

void Array::Display()
{
	for(int i = 0; i < length; i++)
	{
		cout << A[i] <<" ";
	}

	cout << endl;
}

void Array::Append(int x)
{
	if(length < size)
	{
		A[length] = x;
		length++;
	}
}

void Array::Insert(int index, int x)
{
	if (index >= 0 && index <= length)
	{
		for(int i = length; i > index; i--)
		{
			A[i] = A[i -1];
		}
		A[index] = x;
		length++;
	}
}

void Array::Swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int Array::LinearSearch(int key)
{
	for(int i = 0; i < length; i++)
	{
		if (key == A[i])
		{
			return i;
		}
	}
	return -1;
}

int Array::TranspositionLinearSearch(int key)
{
	for(int i =0; i < length; i++)
	{
		if (key == A[i])
		{
			swap(A[i],A[i-1]);
			return i - 1;
		}
	}

	return -1;
}

int Array::MoveToFrontLinearSearch(int key)
{
	for (int i = 0; i < length; i++)
	{
		if (key == A[i])
		{
			swap(A[i], A[0]);
			return 0;
		}
	}

	return -1;
}

int Array::BinarySearchLoop(int key)
{
	int mid, low, high;
	low = 0;
	high = length - 1;

	while(low <= high)
	{
		mid = (low + high) /2;

		if (A[mid] == key)
		{
			return mid;	
		}
		else if(key < A[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return -1;
}

int Array::RecursiveBinarySearch(int low, int high, int key)
{
	int mid;

	if(low <= high)
	{
		mid = (low + high) / 2;

		if (key == A[mid])
		{
			return mid;
		}
		else if (key < A[mid])
		{
			return RecursiveBinarySearch(low, mid -1, key);
		}
		else
		{
			return RecursiveBinarySearch(mid + 1, high,key);
		}
	}

	return -1;
}


int Array::DeleteIndex(int index)
{
	int x = 0;
	if (index >= 0 && index < length)
	{
		x = A[index];
		for(int i = index; i < length - 1; i++)
		{
			A[i] = A[i + 1];
		}
		length--;
	}

	return x; 
}

int Array::Get(int index)
{
	if(index >= 0 && index < length)
	{
		return A[index];
	}
	return -1;
}

void Array::Set(int index, int x)
{
	if (index >= 0 && index < length)
	{
		A[index] = x;
	}
}

int Array::Max()
{
	int max = A[0];

	for(int i = 1; i < length; i++)
	{
		if(A[i] > max)
		{
			max = A[i];
		}
	}

	return max;
}

int Array::Min()
{
	int min = A[0];

	for (int i = 1; i < length; i++)
	{
		if (A[i] < min)
		{
			min = A[i];
		}
	}

	return min;
}

int Array::Sum()
{
	int Total = 0;

	for(int i = 0; i < length; i++)
	{
		Total += A[i];
	}

	return Total;
}

float Array::Average()
{
	return static_cast<float>(Sum()) / length;
}

void Array::ReverseArrayWithAuxiliaryArray()
{
	int *B;
	B = new int[length];
	int i, j;

	for(i = length -1, j = 0; i >= 0; i--, j++)
	{
		B[j] = A[i];
	}
	for(i = 0; i < length; i++)
	{
		A[i] = B[i];
	}

	delete []B;
}

void Array::ReverseArrayWithSwap()
{
	int temp;
	int i, j;

	for(i = 0, j = length - 1; i < j; i++, j--)
	{
		swap(A[i], A[j]);
	}
}

void Array::LeftShiftArray()
{
	for (int i = 0; i < length; i++)
	{
		A[i] = A[i + 1];
	}

	A[length - 1] = 0;
}

void Array::LeftRotateArray()
{
	int temp = A[0];

	for (int i = 0; i < length; i++)
	{
		A[i] = A[i + 1];
	}

	A[length - 1] = temp;
}

void Array::InsertIntoSortedArray(int key)
{
	int i = length - 1;

	if(length == size)
		return;

	while(i >= 0 && A[i] > key)
	{
		A[i+1] = A[i];
		i--;
	}

	A[i + 1] = key;
	length++;
}

bool Array::isArraySorted()
{
	for(int i = 0; i < length - 1; i++)
	{
		if(A[i] > A[i+1])
			return false;
	}

	return true;
}

void Array::ArrangePositiveAndNegatives()
{
	int i = 0;
	int j = length -1;

	while(i < j)
	{
		while (A[i] < 0) {i++;}
		while (A[j] >= 0) {j--;}

		if(i < j)
		{
			swap(A[i], A[j]);
		}
	}
}

Array* Array::MergeArrays(Array arr2)
{
	int i = 0, j = 0, k =0;
	Array *arr3 = new Array[length + arr2.length];

	int m = length;
	int n = arr2.length;

	while(i < m && j < n)
	{
		if(A[i] < arr2.A[j])
		{
			arr3[k++] = A[i++];
		}
		else
		{
			arr3[k++] = arr2.A[j++];
		}
	}
	for(;i < m; i++)
	{
		arr3[k++] = A[i];
	}
	for(;j < n; j++)
	{
		arr3[k++] = arr2.A[j];
	}

	return arr3;
}

Array* Array::Union(Array arr2)
{
	int i = 0, j = 0, k = 0;
	Array* arr3 = new Array[length + arr2.length];
	int m = length;
	int n = arr2.length;

	while(i < m && j < n)
	{
		if(A[i] < arr2.A[j])
		{
			arr3->A[k++] = A[i++];
		}
		else if(arr2.A[j] < A[i])
		{
			arr3->A[k++] = arr2.A[j++];
		}
		else
		{
			arr3->A[k++] = A[i++];
			j++;
		}
	}

	for(; i < m; i++)
	{
		arr3->A[k++] = A[i];
	}
	for(; j < n; j++)
	{
		arr3->A[k++] = A[j];
	}

	return arr3;
}

Array* Array::Intersection(Array arr2)
{
	int i =0, j = 0, k = 0;
	Array* arr3 = new Array(length + arr2.length);
	int m = length;
	int n = arr2.length;

	while(i < m && j < n)
	{
		if(A[i] < arr2.A[j])
		{
			i++;
		}
		else if(arr2.A[j] < A[i])
		{
			j++;
		}
		else
		{
			arr3->A[k++] = A[i++];
			j++;
		}
	}

	return arr3;
}

Array* Array::Difference(Array arr2)
{
	int i = 0, j = 0, k = 0;
	Array* arr3 = new Array(length + arr2.length);

	int m = length;
	int n = arr2.length;

	while(i < m && j < n)
	{
		if(A[i] < arr2.A[j])
		{
			arr3->A[k++] = A[i++];
		}
		else if(arr2.A[j] < A[i])
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
		arr3->A[k++] = A[i];
	}

	return arr3;
}


int main()
{
	int choice, sz;
	int x, index;

	printf("Enter the size of the Array: ");
	scanf_s("%d", &sz);
	Array *arr1 = new Array(sz);

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
			case 1: cout<<"Enter an element and index: ";
				cin>>x>>index;
				arr1->Insert(index, x);
				break;
			case 2: cout<<"Enter index: ";
				cin>>index;
				x = arr1->DeleteIndex(index);
				cout<<"Element that was Deleted: "<<x;
				cout<<endl;
				break;
			case 3: cout<<"Enter element to search: ";
				cin>>x;
				index = arr1->LinearSearch(x);
				cout<<"Element is at index: %d\n"<<index;
				break;
			case 4: cout<<"Sum is: %d\n"<<arr1->Sum();
				break;
			case 5: arr1->Display();
		}
	}while(choice < 6);

	return 0;
}