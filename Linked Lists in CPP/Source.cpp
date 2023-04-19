#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class LinkedList
{
private:
	Node *first;

public:
	LinkedList()
	{
		first=NULL;
	};
	LinkedList(int A[], int n);

	void Display();
	void Insert(int index, int x);
	int Delete(int index);
	int Length();

	~LinkedList();
};

LinkedList::LinkedList(int A[], int n)
{
	Node *last, *temp;

	first = new Node;
	first->data = A[0];
	first->next = NULL;
	last = first;

	for(int i=1; i<n; i++)
	{
		temp = new Node;
		temp->data = A[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

LinkedList::~LinkedList()
{
	Node *p = first;
	while(first)
	{
		first = first->next;
		delete p;
		p = first;
	}
}

void LinkedList::Display()
{
	Node *p = first;

	while(p)
	{
		cout<<p->data<< " ";
		p = p->next;
	}
	cout<<endl;
}

int LinkedList::Length()
{
	Node *p = first;
	int length = 0;

	while(p != NULL)
	{
		length++;
		p = p->next;
	}

	return length;
}

void LinkedList::Insert(int index, int x)
{
	if(index < 0 || index > Length())
		return;
	
	Node *t, *p;
	t = new Node;
	t->data = x;

	if(index == 0)
	{
		t->next = first;
		first = t;
	}
	else if(index > 0)
	{
		p = first;
		for(int i=0; i < index-1 && p; i++)
		{
			p = p->next;
		}
		if(p != NULL)
		{
			t->next = p->next;
			p->next = t;
		}
	}
}

int LinkedList::Delete(int index)
{
	Node *p, *q = NULL;
	int x = -1;

	if(index == 1)
	{
		x= first->data;
		p = first;
		first = first->next;
		delete p;
	}
	else
	{
		p = first;

		for(int i = 0; i < index - 1 && p != NULL; i++)
		{
			q = p;
			p = p->next;
		}
		if(p != NULL)
		{
			q->next = p->next;
			x = p->data;
			delete p;
		}
	}

	return x;
}

int main()
{
	int A[] = {1,2,3,4,5};
	LinkedList linked_list(A, 5);
	linked_list.Display();
	cout<<endl;
	linked_list.Insert(3,10);
	linked_list.Display();
	system("pause");
}