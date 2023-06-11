#include <stdio.h>

/**
 * \ Inserts elements to form a Max Heap. H[i/2] is the parent index of H[i] so index 4's parent would be index 2, and index 3's parent would be index 1
 * as it takes the floor value.
 */
void Insert(int H[], int n)
{
	int temp, i = n;
	temp = H[n]; //stores the value at H[n] in this temp variable for comparison with other elements

	while(i > 1 && temp > H[i/2])
	{
		H[i] = H[i/2];
		i = i/2;
	}

	H[i] = temp;
}

/**
 * \brief 
 * \param H 
 * \param n is the size of the Heap
 */
int Delete(int H[], int n)
{
	int x, i, j, temp;
	int val = H[1];
	x = H[n]; //last element of Heap
	H[1] = H[n];
	H[n] = val;
	i = 1;
	j = 2*i; //sets j to left child of i

	while(j < n-1) //n-1 because the size of the Heap has reduced by 1 already
	{
		if(H[j+1] > H[j]) //if the right child of i is greater than left child of i
			j = j+1;

		if(H[i] < H[j])
		{
			temp = H[i];
			H[i] = H[j];
			H[j] = temp;
			i = j;
			j = 2*j; //new left child of i
		}
		else //i is not less than j, and Heap is properly arranged
			break;
	}

	return val;
}

void Display(int H[])
{
	for(int i=1; i<=7; i++)
	{
		printf("%d ", H[i]);
	}
}

int main()
{
	int H[] = {0,10,20,30,25,5,40,35}; //0 can be ignored as it is only used to make the Heap start from index 1
	
	for(int i=2; i<=7; i++)
	{
		Insert(H, i);
	}

	Display(H);
	printf("\n");

	for(int i = 7; i > 1; i--)
	{
		printf("Deleted Value is: %d\n", Delete(H, i));
	}
	
	printf("Heap Sort of Data is: ");
	Display(H);

	return 0;
}