#include "iostream"
#include "stdio.h"
#include "stdlib.h"

using namespace std;

class Array
{
private:
	int *A;
	int size;
	int length;

	void Swap(int *x, int *y);

public:
	Array();
	Array(int size);
	void Create();
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
	Array* MergeArrays(Array *arr2);
	Array* Union(Array *arr2);
	Array* Intersection(Array *arr2);
	Array* Difference(Array * arr2);

	~Array();
};

Array::Array()
{
	size = 10;
	length = 0;
	A= new int[size];
}
Array::Array(int sz)
{
	size = sz;
	length = 0;
	A = new int [size];
}

void Array::Create()
{
	A[0] = 4;
	A[1] = 8;
	A[2] = 13;
	A[3] = 16;
	A[4] = 20;
}

Array::~Array()
{
	delete [] A;
}

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

Array* Array::MergeArrays(Array *arr2)
{
	int i = 0, j = 0, k =0;
	auto arr3 = new Array[10];

	while(i < length && j < arr2->length)
	{
		if(A[i] < arr2->A[j])
		{
			arr3[k++] = A[i++];
		}
		else
		{
			arr3[k++] = arr2->A[j++];
		}
	}
	for(;i < length; i++)
	{
		arr3[k++] = A[i];
	}
	for(;i < arr2->length; j++)
	{
		arr3[k++] = arr2->A[j];
	}

	arr3[length] = length + arr2->length;
	arr3[size] = 10;

	return arr3;
}


int main()
{
	Array arr(5, 5);
	Array arr2(5, 5);
	int *arr3;
	arr.Create();
	arr.Display();
	arr2.Create2();
	arr3 = arr.MergeArrays(arr, arr2);


	cout << arr3 << endl;

	return 0;
}