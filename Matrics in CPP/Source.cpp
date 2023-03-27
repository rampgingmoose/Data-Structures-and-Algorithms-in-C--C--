#include <iostream>

using namespace std;

class LowerTriangularMatrix
{
private:
	int *A;
	int n;

public:
	LowerTriangularMatrix()
	{
		n = 2;
		A = new int[2*(2+1)/2];
	}

	LowerTriangularMatrix(int n)
	{
		this->n = n;
		A = new int[n*(n+1)/2];
	}

	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
	int GetDimension() {return n;}

	~LowerTriangularMatrix()
	{
		delete []A;
	};
};

void LowerTriangularMatrix::Set(int i, int j, int x)
{
	if(i >= j)
	{
		A[n*(j-1) - (j-2)*(j-1)/2 + i-j] = x;
	}
}

int LowerTriangularMatrix::Get(int i, int j)
{
	if(i >= j)
		return A[n*(j-1) - (j-2)*(j-1)/2 + i-j];
	else
		return 0;
}

void LowerTriangularMatrix::Display()
{
	int i = 0;
	int j = 0;

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(i >= j)
			{
				cout << A[n*(j-1) - (j-2)*(j-1)/2 + i-j] << " ";
			}
			else
			{
				cout << "0 ";
			}
		}

		cout << endl;
	}
}

int main()
{
	int d;
	cout<<"Enter Dimensions";
	cin>>d;

	LowerTriangularMatrix lm(d);

	int x;
	cout<<"Enter all elements";
	for(int i=1; i<=d; i++)
	{
		for(int j = 1; j<=d; j++)
		{
			cin>>x;
			lm.Set(i, j, x);
		}
	}

	lm.Display();

	system("pause");
}
