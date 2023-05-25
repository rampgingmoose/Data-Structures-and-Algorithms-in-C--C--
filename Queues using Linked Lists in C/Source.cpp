#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front=NULL, *rear=NULL;

/**
 * rear pointer should always be pointing on the last Node.
 */
void enqueue(int x)
{
    Node *t = (struct Node*)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("Queue is FULL\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL) //Checks to see if this is the first Node in the queue
            front=rear=t;
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
        printf("Queue is EMPTY\n");
    else
    {
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }

    return x;
}

void Display()
{
    struct Node *p = front;

    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    Display();

    printf("Element deleted: %d \n", dequeue());

    Display();

    return 0;
}