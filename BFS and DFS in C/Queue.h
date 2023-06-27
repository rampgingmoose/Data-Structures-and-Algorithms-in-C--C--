#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));

    if(t == NULL)
        printf("Queue is FULL");
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node *p;
    if(front == NULL)
        printf("Queue is EMPTY");
    else
    {
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }

    return x;
}

int isEmpty()
{
    return front==NULL;
}