#include <iostream>

using namespace std;

class Element
{
public:
	int row; //row number
	int column; //column number
	int x; //element stored at row and column number
};

class SparseMatrix
{
private:
	int totalRows; //total number of rows in matrix
	int totalColumns; //total number of columns in matrix
	int num; //total number of non-zero elements
	Element *element;
public:
	SparseMatrix(int totalRows, int totalColumns, int num)
	{
		//this->totalRows refers to the private member in SparseMatrix while totalRows refers to the formal parameter. Same for other variables
		this->totalRows = totalRows;
		this->totalColumns = totalColumns;
		this->num = num;
		element = new Element[num];
	}

	~SparseMatrix()
	{
		//must delete element to release memory since it is dynamically created
		delete []element;
	}

	SparseMatrix operator+(SparseMatrix &s);
	friend istream & operator>>(istream &is, SparseMatrix &s);
	friend ostream & operator<<(ostream &os, SparseMatrix &s);
};

SparseMatrix SparseMatrix::operator+(SparseMatrix &s)
{
	//check to see if the first and second matrices have the same number of rows and columns, if not then they can not be added and return.
	if(totalRows != s.totalRows || totalColumns != s.totalColumns)
		return SparseMatrix(0,0,0);

	int i,j,k;
	i=j=k=0;
	SparseMatrix *sum = new SparseMatrix(totalRows,totalColumns,num+s.num);

	while(i<num && j<s.num)
	{
		//check to see if the first or second matrix has a smaller number of rows,
		//whichever is smaller copy those values into sum.
		if(element[i].row < s.element[j].row)
			sum->element[k++] = element[i++];
		else if(element[i].row > s.element[j].row)
			sum->element[k++] = s.element[j++];
		else
		{
			//check to see if the first or second matrix has a smaller number of columns,
			//whichever is smaller copy those values into sum.
			if(element[i].column < s.element[j].column)
				sum->element[k++] = element[i++];
			else if(element[i].column > s.element[j].column)
				sum->element[k++] = element[j++];
			else
			{
				//if the first and second matrix have the same number of rows and columns then copy the elements of the first array
				//into sum. Then add the x value of the second matrix to the x value in sum.
				sum->element[k] = element[i++];
				sum->element[k++].x += s.element[j++].x;
			}
		}
	}
	//Copy all remaining elements from the first and second array
	for(;i<num;i++)
		sum->element[k++] = element[i];
	for(;j<s.num;j++)
		sum->element[k++] = s.element[j];

	//Set sum's total number of non-zero elements equal to k as k has been keeping track of how many
	//non-zero elements have been stored in sum
	sum->num = k;
	return *sum;
}


istream & operator>>(istream &is, SparseMatrix &s)
{
	cout<<"Enter non-zero elements";
	for(int i=0; i<s.num; i++)
	{
		cin>>s.element[i].row>>s.element[i].column>>s.element[i].x;
	}

	return is;
}

ostream & operator<<(ostream &os, SparseMatrix &s)
{
	int k=0;

	for(int i=0; i<s.totalRows; i++)
	{
		for(int j=0; j<s.totalColumns; j++)
		{
			if(s.element[k].row == i && s.element[k].column == j)
				cout<<s.element[k++].x<<" ";
			else
				cout<<"0 ";
		}
		cout<<endl;
	}

	return os;
}

int main()
{
	SparseMatrix s1(5,5,5);
	SparseMatrix s2(5,5,5);

	cin>>s1;
	cin>>s2;

	SparseMatrix sum=s1+s2;

	cout<<"First Matrix"<<endl<<s1;
	cout<<"Second Matrix"<<endl<<s2;
	cout<<"Sum Matrix"<<endl<<sum;

	system("pause");
}