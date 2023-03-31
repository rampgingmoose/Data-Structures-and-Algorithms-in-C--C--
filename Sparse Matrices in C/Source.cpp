#include <stdlib.h>
#include <stdio.h>

struct Element
{
	int row; //row number
	int column; //column number
	int x; //non-zero element at that row & column index
};

struct SparseMatrix
{
	int totalRows; //total number of rows
	int totalColumns; //total number of columns
	int num; //total number of non-zero elements
	struct Element *element;
};

void create(struct SparseMatrix *s) //call by reference as it has to modify the struct
{
	printf("Enter Dimensions");
	scanf_s("%d %d",&s->totalRows,&s->totalColumns);
	printf("Number of non-zero elements");
	scanf_s("%d", &s->num);

	s->element = (struct Element *)malloc(s->num*sizeof(struct Element));

	printf("Enter all elements");
	for(int i=0; i < s->num; i++)
	{
		scanf_s("%d%d%d", &s->element[i].row, &s->element[i].column,
			&s->element[i].x);
	}
}

void Display(struct SparseMatrix s) //call be value as it is not modifying the struct
{
	int i, j, k=0;

	for(i=0;i < s.totalRows;i++)
	{
		for(j=0;j < s.totalColumns;j++)
		{
			if(i == s.element[k].row && j == s.element[k].column)
			{
				printf("%d ", s.element[k++].x);
			}
			else
			{
				printf("0 ");
			}
		}

		printf("\n");
	}
}

struct SparseMatrix * add(struct SparseMatrix *s1, struct SparseMatrix *s2)
{
	if(s1->totalRows != s2->totalRows || s1->totalColumns != s2->totalColumns) //check to see if the matrices can be added by seeing if they have the same dimensions
		return 0; //If either the total rows or columns don't match then it is not possible to add these matrices.

	int i, j, k;
	i=j=k=0;

	struct SparseMatrix *sum = (struct SparseMatrix *)malloc(sizeof(struct SparseMatrix));
	sum->totalRows = s1->totalRows;
	sum->totalColumns = s1->totalColumns;
	sum->element = (struct Element *)malloc(s1->num+s2->num*sizeof(struct Element));

	while(i < s1->num && j < s2->num)
	{
		//compare rows of s1 & s2, whichever is smaller copy those elements into sum.
		if(s1->element[i].row < s2->element[j].row)
			sum->element[k++] = s1->element[i++];
		else if(s1->element[i].row > s2->element[j].row)
			sum->element[k++] = s2->element[j++];
		else
		{
			//compare columns of s1 & s2, whichever is smaller copy those elements into sum
			if(s1->element[i].column < s2->element[j].column)
				sum->element[k++] = s1->element[i++];
			else if(s1->element[i].column > s2->element[j].column)
				sum->element[k++] = s2->element[j++];
			else
			{
				//if the rows & columns of s1 & s2 are identical then set sum to the values in s1, then add the x element in s2 to sum's x value.
				sum->element[k] = s1->element[i++];
				sum->element[k++].x += s2->element[j++].x;
			}
		}
	}
	//These two for loops checks for and copies any remaining elements in either the first or second matrix into sum
	for(;i<s1->num;i++)
	{
		sum->element[k++] = s1->element[i];
	}
	for(;j<s2->num;j++)
	{
		sum->element[k++] = s2->element[j];
	}
	//k is tracking the number of non-zero elements we are storing in sum, so we set sum's total number of non-zero elements equal to k
	sum->num=k;
}

int main()
{
	struct SparseMatrix s1, s2, *s3;

	create(&s1);
	create(&s2);
	s3 = add(&s1,&s2);

	printf("First Matrix\n");
	Display(s1);
	printf("Second Matrix\n");
	Display(s2);
	printf("Sum Matrix\n");
	Display(*s3);
	printf("\n");

	return 0;
}