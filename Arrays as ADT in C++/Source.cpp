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
		A = new int[size] {8,5,2,8,9,3,21,16,25,1};
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
	void CountDuplicatesInArraysUsingHashing();
	void FindingDuplicatesInUnsortedArrays();
	void FindPairOfElementsWithSumK();
	void FindPairOfElementsWithSumKUsingHashing();
	void FindPairOfElementsWithSumKSortedArray();
	void FindMinAndMaxInSingleScan();

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
 * \brief Finds all missing elements in an array, sorted or unsorted. Utilizes a very simple hash table(or bit setting) to indicate which
 * elements are present by incrementing the corresponding index in h_table to 1. Any element in h_table with a value of 0 is a missing
 * element.
 */
void Array::FindMultipleMissingElementsUsingHashTable()
{
	int l = Min(); //Smallest element of the given array
	int h = Max(); //Largest element of the given array
	int h_table[17] = {0}; //Size must be set to largest element in A[] + 1, otherwise will cause seg fault 
	int i;

	for(i = 0; i < length; i++)
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

/**
 * \brief Finds all duplicate elements in an array, sorted or unsorted. Utilizes a very simple hash table(or bit setting) to indicate which
 * elements are present by incrementing the corresponding index in h_table to 1. Any element in h_table with a value greater than 1 is
 * a duplicate element, and the value found at h_table[i] is the amount of times it appears.
 */
void Array::CountDuplicatesInArraysUsingHashing()
{
	int l = Min();
	int h = Max();
	int h_table[21] = {0}; //Size must be set to largest element in A[] + 1, otherwise will cause seg fault 

	for(int i = 0; i < length; i++)
	{
		h_table[A[i]]++;
	}
	for(int i = 0; i <= h; i++)
	{
		if(h_table[i] > 1)
			cout<<"duplicate element: "<<i<<" appears: "<<h_table[i]<<" times"<<endl;
	}
}

/**
 * \brief Finds duplicates in an unsorted array, however the time complexity is Quadratic Time. Therefore this method is not recommended
 * and is simply here to better understand arrays. This method involves measuring each element at A[i] to every other element beyond it in
 * the array using a second index(j) to compare the two elements. Using a hash table is recommended instead.
 */
void Array::FindingDuplicatesInUnsortedArrays()
{
	for(int i=0; i < length-1; i++)
	{
		int count = 1;

		if(A[i] != -1)
		{
			for(int j = i+1; j < length; j++)
			{
				if(A[i]==A[j])
				{
					count++;
					A[j] = -1; //This is to prevent an element from being counted twice 
				}
			}
		}

		if(count>1)
		{
			cout<<"duplicate element: "<<A[i]<< " appears: "<<count<< " times."<<endl;
		}
	}
}

/**
 * \brief Finds a pair of elements whose sum is equal to variable k. This function does not account for duplicates; so if there are duplicate
 * elements that satisfy the condition, they will appear as many times as there are duplicates. The time complexity of thisfunciton is
 * Quadratic time so it is not a recommended method to utilize.
 */
void Array::FindPairOfElementsWithSumK()
{
	int k = 28;
	for(int i = 0; i < length-1; i++)
	{
		for(int j = i+1; j<length; j++)
		{
			if(A[i] + A[j] == k)
			{
				cout<<A[i]<<"+"<<A[j]<<"="<<k<<endl;
			}
		}
	}
}

/**
 * \brief Utilizes a simple hash table to find potential matching pairs with a sum of k. h_table[k-A[i]] will go to the resulting index in
 * h_table, if that element has been found then you have a matching pair. That index will be incremented and will continue to loop. Multiple
 * pairs can be found.
 */
void Array::FindPairOfElementsWithSumKUsingHashing()
{
	int k = 28;
	int h = Max();
	int h_table[21] = {0}; //Size must be set to largest element in A[] + 1, otherwise will cause seg fault

	for(int i = 0; i < length; i++)
	{
		if(h_table[k-A[i]] >= 0 && h_table[k-A[i]] != 0) //check for negative index then check to see if element at h_table[k-A[i]] has been found
		{
			cout<<A[i]<<"+"<<k-A[i]<<" is equal to k"<<endl;
		}

		h_table[A[i]]++;
	}
}

/**
 * \brief Since this is a sorted array we know the min element in at A[0] and the max element is at length-1. Therefore, we can take two
 * indices i and j and set them to the min and max elements respectively. While i is less than j check to see if A[i] + A[j] is equal to k
 * if it is increment i and decrement j. If the result is less than k increment i, as a larger element at i + j may equal k, conversely
 * if A[i] + A[j] is greater than k then  decrement j as a smaller element at j may equal k. Time Complexity is Linear Time as each index
 * is only scanning half of the array.
 */
void Array::FindPairOfElementsWithSumKSortedArray()
{
	int k = 31;
	int i = 0;
	int j = length-1;

	while(i<j)
	{
		if(A[i]+A[j] == k)
		{
			cout<<A[i]<<"+"<<A[j]<<" is equal to k"<<endl;
			i++;
			j--;
		}
		else if (A[i]+A[j] < k)
			i++;
		else
			j--;
	}
}

void Array::FindMinAndMaxInSingleScan()
{
	int min = A[0];
	int max = A[0];

	for(int i = 0; i < length; i++)
	{
		if(A[i] < min)
			min = A[i];
		else if(A[i] > max)
			max = A[i];
	}

	cout<<"minimum element is: "<<min<<endl;
	cout<<"maximum element is: "<<max<<endl;
}


int main()
{
	int choice, sz;
	int x, index;

	//cout<<"enter the size of the array: ";
	//cin>>sz;
	Array *arr1 = new Array();
	arr1->FindMinAndMaxInSingleScan();

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