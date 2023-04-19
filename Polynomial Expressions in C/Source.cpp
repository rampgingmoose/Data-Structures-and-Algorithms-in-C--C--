#include <stdio.h>
#include <stdlib.h>

struct Term
{
	int coefficient;
	int exponent;
};

struct Polynomial
{
	int n; //total number of non-zero terms
	struct Term *terms;
};

void Create(struct Polynomial *p)
{
	printf("Enter number of terms: ");
	scanf_s("%d", &p->n);
	p->terms = (struct Term*)malloc(p->n*sizeof(struct Term));

	printf("Enter term followed by exponent\n");
	for(int i=0; i < p->n; i++)
	{
		scanf_s("%d%d", &p->terms[i].coefficient, &p->terms[i].exponent);
	}
}

void Display(struct Polynomial p)
{
	for(int i=0; i<p.n; i++)
	{
		printf("%dx%d+",p.terms[i].coefficient, p.terms[i].exponent);
	}
	printf("\n");
}

struct Polynomial * Addition(struct Polynomial *p1, struct Polynomial *p2)
{
	int i,j,k;
	i=j=k=0;
	struct Polynomial *sum;
	sum = (struct Polynomial *)malloc(sizeof(struct Polynomial));
	sum->terms = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));

	while(i < p1->n && j < p2->n)
	{
		if(p1->terms[i].exponent > p2->terms[j].exponent)
		{
			sum->terms[k++] = p1->terms[i++];
		}
		else if(p2->terms[j].exponent > p1->terms[i].exponent)
		{
			sum->terms[k++] = p2->terms[j++];
		}
		else
		{
			sum->terms[k].exponent = p1->terms[i].exponent;
			sum->terms[k++].coefficient = p1->terms[i++].coefficient + p2->terms[j++].coefficient;
		}
	}

	//Copies any remaining elements in either p1 or p2 into sum
	for(;i < p1->n; i++)
	{
		sum->terms[k++] = p1->terms[i];
	}
	for(;j < p1->n; j++)
	{
		sum->terms[k++] = p2->terms[j];
	}

	//set sum's total number of non-zero elements to k as k has been tracking how many non-zero elements have been added into sum
	sum->n = k;
	return sum;
}

int main()
{
	struct Polynomial p1,p2, *p3;

	Create(&p1);
	Create(&p2);

	p3=Addition(&p1, &p2);

	printf("\n");
	Display(p1);
	printf("\n");
	Display(p2);
	printf("\n");
	Display(*p3);

	system("pause");
}