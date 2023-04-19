#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL, *second=NULL, *third=NULL;

void Create(int A[], int n) //n is for the number of elements in the array
{
	struct Node *temp,*last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;

	for(int i=1; i<n; i++) //i starts from 1 as the 0 element is already created
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = A[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

void Create2(int A[], int n) //n is for the number of elements in the array
{
	struct Node *temp,*last;
	second = (struct Node *)malloc(sizeof(struct Node));
	second->data = A[0];
	second->next = NULL;
	last = second;

	for(int i=1; i<n; i++) //i starts from 1 as the 0 element is already created
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = A[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

void Display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

void RecursiveDisplay(struct Node *p)
{
	if(p != NULL)
	{
		printf("%d ",p->data);
		RecursiveDisplay(p->next);
	}
}

/**
 * Determines the length of a linked list by traversing the list and counting each node.
 */
int CountNumberOfNodes(struct Node *p)
{
	int count = 0;

	while(p != 0)
	{
		count++;
		p = p->next;
	}

	return count;
}

/**
 * recursively finds the length of a linked list
 */
int RecursiveCount(struct Node *p)
{
	if(p == 0)
		return 0;
	else
		return RecursiveCount(p->next) + 1;
}

/**
 * adds all elements found in a linked list
 */
int AddAllElementsInList(struct Node *p)
{
	int sum = 0;

	while(p)
	{
		sum += p->data;
		p = p->next;
	}

	return sum;
}

/**
 * recursively adds all the elements in a linked list
 */
int RecursiveAddAllElements(struct Node *p)
{
	if(!p)
		return 0;
	else
		return RecursiveAddAllElements(p->next) + p->data;
}

int FindMaxElement(struct Node *p)
{
	int maxElement = INT_MIN;

	while(p != NULL)
	{
		if(p->data > maxElement)
			maxElement = p->data;
		p = p->next;
	}

	return maxElement;
}

int FindMinElement(struct Node *p)
{
	int minElement = INT_MAX;

	while (p != NULL)
	{
		if(p->data < minElement)
			minElement = p->data;
		p = p->next;
	}

	return minElement;
}

int RecursiveFindMaxElement(struct Node *p)
{
	int maxElement = 0;

	if(p == NULL)
		return maxElement;
	else
	{
		maxElement = RecursiveFindMaxElement(p->next);
		if(maxElement > p->data)
			return maxElement;
		else
			return p->data;
	}
}

/**
 * \brief 
 * Searches the Nodes in a Linked List one by one for the given key.
 */
struct Node * LinearSearch(struct Node *p, int key)
{
	while(p != NULL)
	{
		if(key == p->data)
			return p;
		p=p->next;
	}

	return NULL;
}

struct Node * RecursiveLinearSearch(struct Node *p, int key)
{
	if(p == NULL)
		return NULL;
	if(key == p->data)
		return p;
	return RecursiveLinearSearch(p->next, key);
}

/**
 * If a Node's data is equal to the given key, then that Node will be moved to the first Node in the list.
 * This improves search time if that same key is given the next time a search is performed, and the new Time
 * Complexity will be constant time.
 */
struct Node * MoveToHeadLinearSearch(struct Node *p, int key)
{
	struct Node *q = NULL;

	while(p != 0)
	{
		if(key == p->data)
		{
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next;
	}

	return NULL;
}

void Insert(struct Node *p,int index, int x)
{
	if(index < 0 || index > CountNumberOfNodes(p)) //checks to see if the index is valid, if less than 0: invalid, if greater than length of List: invalid
		return;

	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = x;

	if(index == 0) //We are inserting before the first node
	{
		temp->next = first;
		first = temp;
	}
	else if(index > 0) //We are inserting at a given index anywhere after the first node
	{
		for(int i = 0; i < index-1; i++)
		{
			p = p->next;
		}
		if(p != NULL)
		{
			temp = new Node;
			temp->data = x;
			temp->next = p->next;
			p->next = temp;
		}
	}
}

void SortedListInsert(struct Node *p, int x)
{
	struct Node *q, *temp;
	q=temp=NULL;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;

	if(first==NULL)
	{
		first = temp;	
	}
	else
	{
		while(p != NULL && p->data < x)
		{
			q = p;
			p = p->next;
		}
		if(p==first)
		{
			temp->next = first;
			first = temp;
		}
		else
		{
			temp->next = q->next;
			q->next = temp;	
		}
	}
}

int DeleteNode(struct Node *p, int index)
{
	if(index < 1 || index > CountNumberOfNodes(p)) //Checks for valid index. Less than 1 is invalid, and greater than list length is invalid.
		return -1;

	struct Node *q = NULL;
	int x = -1;

	if(index == 1)
	{
		x = first->data;
		q = first;
		first = first->next;
		free(q);
	}
	else
	{
		//Checking for invalid index is done at beginning of function so no need to do it here.
		for(int i = 0; i < index-1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		free(p);
	}

	return x;
}

int isSorted(struct Node *p)
{
	int x = INT_MIN;

	while(p != NULL)
	{
		if(p->data < x)
			return 0; //false
		else
		{
			x = p->data;
			p = p->next;
		}
	}

	return 1; //true
}

void RemoveDuplicates(struct Node *p)
{
	struct Node *q = first->next;

	while(q != NULL)
	{
		if(p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			free(q);
			q = p->next;
		}
	}
}

void ReverseElementsOfList(struct Node *p)
{
	int *A = (int *)malloc(sizeof(int)*CountNumberOfNodes(p));
	struct Node *q = first;
	int i = 0;

	while(q != NULL)
	{
		A[i] = q->data;
		q = q->next;
		i++;
	}
	q = p;
	i--;
	while(q != NULL)
	{
		q->data = A[i--];
		q = q->next;
	}
}

/**
 * Reverse links of list using sliding pointers
 */
void ReverseLinksOfList(struct Node *p)
{
	struct Node *q = NULL;
	struct Node *r = NULL;

	while(p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}

	first= q;
}

/**
 * q should be passed in as NULL and p should be passed in as the first pointer.
 */
void RecursiveReverseLinksOfList(struct Node *q, struct Node *p)
{
	if(p != NULL)
	{
		RecursiveReverseLinksOfList(p,p->next);
		p->next = q; //Executed at returning time
	}
	else
	{
		first = q; //Sets the last node in the list to the first node
	}
}

void ConcatenateLists(struct Node *p, struct Node *q)
{
	third = p;

	while(p->next!=NULL)
	{
		p = p->next;
	}
	p->next = q;
	q = NULL;
}

struct Node * MergeSortedLinkedLists(struct Node *p, struct Node *q)
{
	struct Node *last = NULL;
	if(p->data < q->data)
	{
		third=last=p;
		p = p->next;
		last->next = NULL;
	}
	else
	{
		third=last=q;
		q = q->next;
		last->next = NULL;
	}
	while(p!=NULL && q!=NULL)
	{
		if(p->data < q->data)
		{
			last->next = p;
			last = p;
			p = p->next;
			last->next = NULL;
		}
		else
		{
			last->next = q;
			last = q;
			q = q->next;
			last->next = NULL;
		}
	}
	if(p!=NULL)
	{
		last->next = p;
		last = p;
	}
	if(q!=NULL)
	{
		last->next = q;
		last = q;
	}

	return third;
}

/**
 * Checks to see if the Linked List has a Loop or if it is Linear. Utilizes two temporary pointers, and a formal parameter to the first Node
 * must be passed in by pointer. Pointer q moves two Nodes at a time and p moves by one, if p and q are ever equal to each other after leaving
 * the first Node then there is a Loop. If p or q becomes NULL then the List is Linear.
 */
int isLoop(struct Node *f)
{
	struct Node *p, *q;
	p=q=f;

	do
	{
		p = p->next;
		q = q->next;
		q=q?q->next:q;
	}while(p && q && p!=q);

	if(p==q)
		return true;
	else
		return false;
}

int main()
{
	struct Node *t1, *t2;
	int A[]={3,5,7,9,10};
	Create(A, 6);

	t1=first->next->next;
	t2=first->next->next->next->next;
	t2->next=t1;

	printf("%d\n", isLoop(first));

	return 0;
}