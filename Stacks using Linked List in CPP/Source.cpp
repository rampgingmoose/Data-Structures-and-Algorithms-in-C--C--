#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class Stack
{
private:
	Node *top;

public:
	Stack(){top = NULL;}
	void push(int x);
	int pop();
	void display();
};

void Stack::push(int x)
{
	Node *temp = new Node;

	if(temp == NULL)
		cout<<"Stack is Full"<<endl;
	else
	{
		temp->data = x;
		temp->next = top;
		top = temp;
	}
}

int Stack::pop()
{
	Node *p;
	int x = -1;

	if(top == NULL)
		cout<<"Stack is Empty"<<endl;
	else
	{
		p = top;
		top = top->next;
		x = p->data;
		delete p;
	}

	return x;
}

void Stack::display()
{
	if(top == NULL)
		cout<<"Stack is empty"<<endl;

	Node *p;
	p = top;

	while(p != NULL)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	Stack stk;

	stk.push(10);
	stk.push(20);
	stk.push(30);

	stk.display();
	cout<<stk.pop()<<endl;
	stk.display();
	system("pause");
}