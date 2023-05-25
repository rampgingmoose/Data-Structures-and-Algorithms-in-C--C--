#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild; //leftchild pointer
    int data;
    struct Node *rchild; //rightchild pointer
};

struct Queue
{
    int size;
    int front;
    int rear;
    Node **Q; //Double pointer for an array to store Nodes
};

//front and rear initialized to 0 for circular queue implementation
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (Node **)malloc(q->size * sizeof(Node *)); //array of pointers created
}

//implements a given element into the queue circularly
void enqueue(struct Queue *q, Node * x)
{
    if((q->rear + 1) % q->size == q->front )
        printf("Queue is Full\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

//dequeues elements circularly
Node * dequeue(struct Queue *q)
{
    Node* x = NULL;

    if(q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }

    return x;
}

int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}