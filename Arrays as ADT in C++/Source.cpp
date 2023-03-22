#include <iostream>

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
		length = 10;
		A = new int[size] {3,6,8,8,10,12,15,15,15,20};
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
	int FindingMissingElement();
	int FindingMissingElementNonNaturalSum();
	void FindingMultipleMissingElements();
	void FindMultipleMissingElementsUsingHashTable();
	void FindingDuplicatesInASortedArray();
	void CountDuplicateElementsInASortedArray();

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

/**
 *Finds the missing element in array provided that the array is the sum of first natural numbers.
 *This means this function can only be used if the array begins with 1 and continues sequentially, e.g. 1,2,3,4,5,etc.
 */
int Array::FindingMissingElement()
{
	int total = 0;

	for(int i = 0; i < length; i++)
	{
		total += A[i];
	}

	int n = A[length - 1];

	int sumOfNaturalNumbers = (n * (n + 1)) / 2;
	int missingElement = sumOfNaturalNumbers - total;

	return missingElement;
}

/**
 * Finds an element in an array that is NOT the sum of first natural numbers, e.g. 6,7,8,9,10,etc
 */
int Array::FindingMissingElementNonNaturalSum()
{
	int l = A[0];
	int h = A[length -1];
	int diff = l - 0;

	for(int i = 0; i < length; i++)
	{
		if(i+diff < l || i+diff > h)
		{
			cout<<"there are ";
			return 0;
		}
		else if(A[i] - i != diff)
		{
			return i+diff;
		}
	}
}

void Array::FindingMultipleMissingElements()
{
	int l = A[0];
	int h = A[length -1];
	int diff = l - 0;

	for(int i = 0; i < length; i++)
	{
		if(A[i] - i != diff)
		{
			while(diff < A[i] - i)
			{
				cout<<"missing element: "<<i+diff<<endl;
				diff++;
			}
		}
	}
}

/**
 * \brief Finds all missing elements an array, sorted or unsorted. Utilizes a very simple hash table(or bit setting) to indicate which
 * elements are present by incrementing the corresponding index in h_table to 1. Any element in h_table with a value of 0 is a missing
 * element.
 */
void Array::FindMultipleMissingElementsUsingHashTable()
{
	int l = Min(); //Smallest element of the given array
	int h = Max(); //Largest element of the given array
	int h_table[17] = {0}; //Size must be set to the max element in a given array
	int i;

	for(i = 0; i < length-1; i++)
	{
		h_table[A[i]]++; //Will go to the corresponding index in h_table and increment the value. E.g A[6] = 8 which == h_table[8]++
	}
	for(i = l; i <= h; i++)
	{
		if(h_table[i] == 0)
		{
			cout << "missing element: "<< i << endl;
		}
	}
}

/**
 * \brief Finds duplicate elements in a given array, Array must be sorted. Function will not print out multiple duplicates
 */
void Array::FindingDuplicatesInASortedArray()
{
	int lastDuplicate = 0;

	for(int i = 0; i < length -1; i++)
	{
		if(A[i] == A[i+1] && A[i] != lastDuplicate) //if the current element == lastDuplicate that element will be skipped
		{
			cout << "duplicate element found: " << A[i] << endl;
			lastDuplicate = A[i]; //duplicate element stored in lastDuplicate
		}
	}
}

/**
 * \brief Finds and counts duplicates in a sorted array. Once i has found a duplicate, j will be set to i and increment as long as the element
 * at each index is equal to each other. Once they are unequal the loop will break and i will be set to j-1 as you want i to skip the elements
 * j has already looped through to prevent repeats. The time complexity is O(n) despite the nested while loop as only a small portion of the
 * array will be looped through resulting in negligible time taken. 
 */
void Array::CountDuplicateElementsInASortedArray()
{
	int i, j;

	for(i =0; i < length - 1; i++)
	{
		if(A[i]==A[i+1])
		{
			j = i+1;

			while(A[j] == A[i])
			{
				j++;
			}
			cout << A[i] <<" is appearing " << j-i << " times" << endl;
			i = j-1;
		}
	}
}


int main()
{
	int choice, sz;
	int x, index;

	//cout<<"enter the size of the array: ";
	//cin>>sz;
	Array *arr1 = new Array();
	arr1->CountDuplicateElementsInASortedArray();

	/*do
	{
		cout<<"menu"<<endl;
		cout<<"1. insert"<<endl;
		cout<<"2. delete"<<endl;
		cout<<"3. search"<<endl;
		cout<<"4. sum"<<endl;
		cout<<"5. display"<<endl;
		cout<<"6. exit"<<endl;

		cout<<"enter you selection: ";
		cin>>choice;

		switch(choice)
		{
			case 1: cout<<"enter an element and index: ";
				cin>>x>>index;
				arr1->Insert(index, x);
				break;
			case 2: cout<<"enter index: ";
				cin>>index;
				x = arr1->DeleteIndex(index);
				cout<<"element that was deleted: "<<x;
				cout<<endl;
				break;
			case 3: cout<<"enter element to search: ";
				cin>>x;
				index = arr1->LinearSearch(x);
				cout<<"element is at index: "<<index;
				break;
			case 4: arr1->FindingMultipleMissingElements();
				break;
			case 5: arr1->Display();
		}
	}while(choice < 6);*/

	return 0;
}