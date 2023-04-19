#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int coefficient;
    int exponent;
    struct Node *next;
}*poly = NULL;

void Create()
{
    struct Node *temp;
    struct Node *last = NULL;
    int num; //number of terms in polynomial expression

    printf("Enter number of terms");
    scanf_s("%d", &num);
    printf("Enter each term with coefficient and exponent");

    for(int i=0; i<num;i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        scanf_s("%d%d",&temp->coefficient, &temp->exponent);
        temp->next = NULL;

        if(poly==NULL) //Inserting the first node in the list
        {
            poly=last=temp;
        }
        else //insert node as the last node in the list
        {
            last->next = temp;
            last = temp;
        }
    }
}

void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%dx%d + ", p->coefficient, p->exponent);
        p = p->next;
    }
    printf("\n");
}

long Eval(struct Node *p,int x)
{
    long sum = 0;
    
    while(p)
    {
        sum += p->coefficient * pow(x, p->exponent);
        p=p->next;
    }

    return sum;
}

int main()
{
    Create();
    Display(poly);
    printf("%ld\n", Eval(poly, 1));
}