#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *previous;
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[], int n)
{
    struct Node *temp, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->previous = NULL;
    first->next = NULL;
    last = first;

    for(int i = 1; i < n; i++)
    {
        temp=(struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = last->next;
        temp->previous = last;
        last->next = temp;
        last = temp;
    }
}

void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p= p->next;
    }
    printf("\n");
}

int GetListLength(struct Node *p)
{
    int length = 0;

    while(p != NULL)
    {
        length++;
        p = p->next;
    }

    return length;
}

void Insert(struct Node *p, int index, int x)
{
    if(index < 0 || index > GetListLength(p))
        return;

    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;

    if(index == 0)
    {
        temp->previous = NULL;
        temp->next = first;
        first->previous = temp;
        first = temp;
    }
    else
    {
        for(int i =0; i < index -1; i++)
        {
            p = p->next;
        }
        
        temp->next = p->next; 
        temp->previous = p;
        if(p->next != NULL)
        {
            p->next->previous = temp;
        }
        p->next = temp;
    }
}

int Delete(struct Node *p, int index)
{
    if(index < 1 || index > GetListLength(p))
        return -1;

    int x = -1;

    if(index == 1)
    {
        first = first->next;
        if(first != NULL)
            first->previous = NULL;
        x = p->data;
        free(p);
    }
    else
    {
        for(int i=0; i < index - 1; i++)
        {
            p = p->next;
        }

        p->previous->next = p->next;
        if(p->next != NULL)
        {
            p->next->previous = p->previous;    
        }

        x = p->data;
        free(p);
    }

    return x;
}

void ReverseList(struct Node *p)
{
    struct Node *temp;

    while(p != NULL)
    {
        temp = p->next;
        p->next = p->previous;
        p->previous = temp;
        p = p->previous;

        if(p != NULL && p->next == NULL)
            first = p;
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    Create(A, 5);

    Display(first);

    ReverseList(first);
    Display(first);

    return 0;
}