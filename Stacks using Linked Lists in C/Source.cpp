#include <cstring>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

/**
 * Inserts a new Node with the given data by the actual parameter. Always pushes a new Node before the first Node
 * in the List. This is done because inserting before the first Node takes Constant Time, while inserting after the
 * last Node would take Linear Time. This is due to having to traverse the entire stack to find the last Node.
 */
void Push(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    if(temp == NULL)
        printf("Stack is full\n");
    else
    {
        temp->data = x;
        temp->next = top;
        top= temp;
    }
}

/**
 * Deletes the first Node in the List, which is the Top Node (Last Node inserted). Returns the data found in the deleted Node.
 */
char Pop()
{
    int x = -1;
    struct Node *temp = top;

    if(top == NULL)
        printf("Stack is empty\n");
    else
    {
        x = temp->data;
        top = temp->next;
        free(temp);
    }

    return x; //If x is return as -1, then the stack was empty
}

void Display()
{
    struct Node *p;
    p = top;

    while(p != NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int Peek(int index)
{
    struct Node *temp;
    int x = -1;
    if(top == NULL)
        printf("Stack is Empty\n");
    else
    {
        temp = top;
        for(int i=0; temp!=NULL && i<index-1; i++)
        {
            temp = temp->next;
        }
        if(temp!=NULL)
        {
            x = temp->data;
        }
    }

    return x;
}



int isBalanced(const char *exp)
{
    struct Node st;

    for(int i=0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(')
            Push(exp[i]);
        else if(exp[i]==')')
        {
            if(top == NULL)
                return 0;
            Pop();
        }
    }

    if(top == NULL)
        return 1;
    else
        return 0;
}

int isOperand(char x)
{
    if(x == '+'|| x== '-'|| x=='*'|| x=='/')
        return 0;
    else
        return 1;
}

int precedence(char x)
{
    if(x=='+'|| x=='-')
        return 1;
    else if(x=='*'|| x=='/')
        return 2;
    return 0;
}

char * InfixToPostfix(const char *infix)
{
    char *postfix;
    long len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char));
    int i=0, j=0;

    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(precedence(infix[i]) > precedence(top->data))
                Push(infix[i++]);
            else
                postfix[j++] = Pop();
        }
    }
    while(top!=NULL)
    {
        postfix[j++] = Pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int EvaluatePostfixExpression(const char *postfix)
{
    int x1, x2, result;

    for(int i=0; postfix[i] != '\0'; i++)
    {
        if(isOperand(postfix[i]))
            Push(postfix[i]-'0');
        else
        {
            x2 = Pop(); x1 = Pop();
            switch(postfix[i])
            {
                case '+': 
                    result = x1 + x2;
                    Push(result);
                    break;
                case '-':
                    result = x1 - x2;
                    Push(result);
                    break;
                case '*':
                    result = x1 * x2;
                    Push(result);
                    break;
                case '/':
                    result = x1 / x2;
                    Push(result);
                    break;
                default:
                    break;
            }
        }
    }

    return top->data;
}

int main()
{
    const char *postfix = "35*62/+4-";

    printf("%d",EvaluatePostfixExpression(postfix));

    return 0;
}