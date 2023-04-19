#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*Head;

void create(int A[], int n)
{
    int i;
    struct Node *temp, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for(i=1; i<n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void Display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    }while(h != Head);

    printf("\n");
}

void RecursiveDiplay(struct Node *h)
{
    static int flag = 0;

    if(h != Head || flag == 0)
    {
        flag = 1;
        printf("%d ", h->data);
        RecursiveDiplay(h->next);
    }

    flag = 0;
}

int GetListLength(struct Node *h)
{
    int length = 0;
    
    do
    {
        length++;
        h = h->next;
    }while(h != Head);

    return length;
}

void Insert(struct Node *h,int index, int x)
{
    if(index < 0 || index > GetListLength(h))
        return;

    Node *t;
    t = new Node;
    t->data = x;

    if(index == 0)
    {
        if(Head == NULL)
        {
            t = Head;
            Head->next = Head;
        }
        else
        {
            while(h->next != Head)
                h = h->next;
            h->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        for(int i = 0; i < index-1; i++)
            h = h->next;
        t->next = h->next;
        h->next = t;
    }
}

int Delete(struct Node *h, int index)
{
    if(index < 1 || index > GetListLength(h))
        return -1; //invalid index

    Node *q;
    int x;

    if(index == 1)
    {
        while(h->next != Head)
        {
            h = h->next;
        }

        x = Head->data;

        if(h == Head)
        {
            free(Head);
            Head = NULL;
        }
        else
        {
            h->next = Head->next;
            free(Head);
            Head = h->next;
        }
    }
    else
    {
        for(int i =0; i < index - 2; i++)
        {
            h = h->next;
        }
        q = h->next;
        h->next = q->next;
        x = q->data;
        free(q);
    }

    return x;
}

int main()
{
    int A[] = {2,3,4,5,6};
    create(A,5);
    Display(Head);

    printf("%d \n", Delete(Head, 2));
    Display(Head);

    return 0;
}