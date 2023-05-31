#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *lchild;
	int data;
	struct Node *rchild;
}*root=NULL;

void Insert(int key)
{
	Node *t = root;
	struct Node *r = NULL; //tail pointer
	struct Node *p = NULL;

	if(root == NULL)
	{
		p = (struct Node *)malloc(sizeof(struct Node));
		p->data = key;
		p->lchild = p->rchild = NULL;
		root = p;
		return;
	}

	while(t != NULL)
	{
		r = t;
		if(key < t->data)
			t = t->lchild;
		else if(key > t->data)
			t = t->rchild;
		else
			return;
	}

	p = (struct Node *)malloc(sizeof(struct Node));
	p->data = key;
	p->lchild = p->rchild = NULL;

	if(key < r->data)
		r->lchild = p;
	else
		r->rchild = p;
}

struct Node * RecursiveInsert(struct Node *p, int key)
{
	struct Node *temp = NULL;
	if(p == NULL)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = key;
		temp->lchild = temp->rchild = NULL;
		return temp;
	}

	if(key < p->data)
		p->lchild = RecursiveInsert(p->lchild, key);
	else if(key > p->data)
		p->rchild = RecursiveInsert(p->rchild, key);

	return p;
}

void InOrderTraversal(struct Node *p)
{
	if(p != NULL)
	{
		InOrderTraversal(p->lchild);
		printf("%d ", p->data);
		InOrderTraversal(p->rchild);
	}
}

struct Node * Search(int key)
{
	struct Node *t = root;

	while(t != NULL)
	{
		if(key == t->data)
			return t;
		else if(key < t->data)
			t = t->lchild;
		else
			t = t->rchild;
	}

	return NULL;
}

int Height(struct Node *p)
{
	int x, y;
	if(p == NULL)
		return 0;
	x = Height(p->lchild);
	y = Height(p->rchild);

	return x>y?x+1:y+1;
}

struct Node * InorderPredecessor(struct Node *p)
{
	while(p != NULL && p->rchild != NULL)
		p = p->rchild;

	return p;
}

struct Node * InorderSuccessor(struct Node *p)
{
	while(p != NULL && p->lchild != NULL)
		p = p->lchild;

	return p;
}

struct Node * Delete(struct Node *p, int key)
{
	struct Node *q;

	if(p == NULL)
		return NULL;
	if(p->lchild == NULL && p->rchild == NULL)//p is a leaf Node and it itself must be deleted
	{
		if(p == root)
			root = NULL;
		free(p);
		return NULL;
	}

	if(key < p->data)
		p->lchild = Delete(p->lchild, key);
	else if(key> p->data)
		p->rchild = Delete(p->rchild, key);
	else
	{
		if(Height(p->lchild) > Height(p->rchild))
		{
			q = InorderPredecessor(p->lchild);
			p->data = q->data;
			p->lchild = Delete(p->lchild, q->data);
		}
		else
		{
			q = InorderSuccessor(p->rchild);
			p->data = q->data;
			p->rchild = Delete(p->rchild, q->data);
		}
	}

	return p;
}

int main()
{
	struct Node *temp;
	root = RecursiveInsert(root, 50);
	RecursiveInsert(root, 10);
	RecursiveInsert(root, 40);
	RecursiveInsert(root, 20);
	RecursiveInsert(root, 30);

	Delete(root, 50);

	InOrderTraversal(root);
	printf("\n");

	temp = Search(20);
	if(temp != NULL)
		printf("Element %d is found\n", temp->data);
	else
		printf("Element is not found\n");

	return 0;
}