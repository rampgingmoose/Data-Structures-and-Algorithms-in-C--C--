#include <iostream>
#include "Tree_Header.h"

using namespace std;

class Tree
{
private:
	Node *root;

public:
	Tree()
	{
		root = NULL;
	}
	void CreateTree();
	void PreOrder(){PreOrder(root);}
	void PreOrder(Node *p);
	void PostOrder(){PostOrder(root);}
	void PostOrder(Node *p);
	void InOrder(){InOrder(root);}
	void InOrder(Node *p);
	void LevelOrder(){LevelOrder(root);}
	void LevelOrder(Node *root);
	int Height(){return Height(root);}
	int Height(Node *root);
};

void Tree::CreateTree()
{
	Node *p, *t;
	int x;
	Queue q(100);

	cout<<"Enter root value: ";
	cin>>x;
	root = new Node;
	root->data = x;
	root->lchild = root->rchild = NULL;
	q.enqueue(root);

	while(!q.isEmpty())
	{
		p = q.dequeue();
		cout<<"Enter Left Child: ";
		cin>>x;
		if(x != -1)
		{
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			q.enqueue(t);
		}
		cout<<"Enter Right Child: ";
		cin>>x;
		if(x != -1)
		{
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			q.enqueue(t);
		}
	}
}

void Tree::PreOrder(Node *p)
{
	if(p != NULL)
	{
		cout<<p->data<<" ";
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}

void Tree::InOrder(Node *p)
{
	if(p!=NULL)
	{
		InOrder(p->lchild);
		cout<<p->data<<" ";
		InOrder(p->rchild);
	}
}

void Tree::PostOrder(Node *p)
{
	if(p != NULL)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		cout<<p->data<<" ";
	}
}

void Tree::LevelOrder(Node *p)
{
	Queue q(100);

	cout<<p->data<<" ";
	q.enqueue(p);

	while(!q.isEmpty())
	{
		p = q.dequeue();
		if(p->lchild)
		{
			cout<<p->lchild->data<<" ";
			q.enqueue(p->lchild);
		}
		if(p->rchild)
		{
			cout<<p->rchild->data<<" ";
			q.enqueue(p->rchild);
		}
	}
}

int Tree::Height(Node *root)
{
	int x=0, y=0;
	if(root == 0)
		return 0;
	x = Height(root->lchild);
	y = Height(root->rchild);
	if(x > y)
		return x + 1;
	else
		return y + 1;
}


int main()
{
	Tree t;
	t.CreateTree();
	cout<<"Preorder: ";
	t.PreOrder();
	cout<<endl;
	cout<<"Inorder: ";
	t.InOrder();
	cout<<endl;
	cout<<"LevelOrder: ";
	t.LevelOrder();
	cout<<endl;
	cout<<"Height: "<<t.Height()<<endl;

	system("pause");
}