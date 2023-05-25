#include <stdio.h>
#include "Queue.h"
#include "Stack.h"

//global variables
struct Node *root=NULL;

void TreeCreate()
{
	struct Node *p, *t;
	int x;
	struct Queue q;

	create (&q, 100);

	printf("Enter root value");
	scanf_s("%d", &x);
	root = (struct Node *)malloc(sizeof(struct Node));
	root->data = x;
	root->lchild = root->rchild = NULL;
	enqueue(&q, root);

	while(!isEmpty(q))
	{
		p = dequeue(&q);
		printf("Enter left child of %d ", p->data);
		scanf_s("%d", &x);
		if(x != -1)
		{
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			enqueue(&q, t);
		}
		printf("Enter Right Child of %d ", p->data);
		scanf_s("%d", &x);
		if(x != -1)
		{
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild= NULL;
			p->rchild = t;
			enqueue(&q, t);
		}
	}
}

void preorder(struct Node *p)
{
	if(p != NULL)
	{
		printf("%d ", p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void InOrder(struct Node *p)
{
	if(p != NULL)
	{
		InOrder(p->lchild);
		printf("%d ", p->data);
		InOrder(p->rchild);
	}
}

void PostOrder(struct Node *p)
{
	if(p != NULL)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%d ", p->data);
	}
}

void IterativePreOrder(struct Node *p)
{
	struct Stack stk;
	StackCreate(&stk, 100);

	while(p != NULL || !isEmptyStack(stk))
	{
		if(p!=NULL)
		{
			printf("%d ", p->data);
			push(&stk, p);
			p = p->lchild;
		}
		else
		{
			p = pop(&stk);
			p = p->rchild;
		}
	}
}

void IterativeInOrder(struct Node *p)
{
	struct Stack stk;
	StackCreate(&stk, 100);

	while(p != NULL || !isEmptyStack(stk))
	{
		if(p != NULL)
		{
			push(&stk, p);
			p = p->lchild;	
		}
		else
		{
			p = pop(&stk);
			printf("%d ", p->data);
			p=p->rchild;
		}
	}
}

/**
 * \brief 
 * \param p p is representative of a local variable of type root node
 */
void IterativeLevelOrder(struct Node *p)
{
	struct Queue q;
	create(&q, 100);
	printf("%d ", p->data);
	enqueue(&q, p);

	while(!isEmpty(q))
	{
		p = dequeue(&q);
		if(p->lchild != NULL)
		{
			printf("%d ", p->lchild->data);
			enqueue(&q, p->lchild);
		}
		if(p->rchild != NULL)
		{
			printf("%d ", p->rchild->data);
			enqueue(&q, p->rchild);
		}
	}
}

int Count(struct Node *p)
{
	int x, y;

	if(p != NULL)
	{
		x = Count(p->lchild);
		y = Count(p->rchild);
		return x + y + 1;
	}
	return 0; //If p is Null then return 0;
}

int Height(struct Node *p)
{
	int x = 0,y = 0;

	if(p == NULL)
		return 0;
	x = Height(p->lchild);
	y = Height(p->rchild);

	if(x>y)
	{
		return x+1;
	}
	else
	{
		return y+1;	
	}
}

int main()
{
	TreeCreate();

	printf("%d ", Count(root));
	printf("%d ", Height(root));

	return 0;
}