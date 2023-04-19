#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void Create(struct Stack *st)
{
    printf("Enter size");
    scanf_s("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(sizeof(st->size *sizeof(int)));
}

void Display(struct Stack st)
{
    if(st.top == -1)
        printf("Stack is empty");
    else
    {
        for(int i=st.top; i>=0; i--)
        {
            printf("%d ",st.S[i]);
        }
    }
    printf("\n");
}

void Push(struct Stack *st, int x)
{
    if(st->top == st->size -1)
        printf("Stack overflow \n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int Pop(struct Stack *st)
{
    int x = -1;

    if(st->top == -1)
        printf("Stack Underflow");
    else
    {
        x = st->S[st->top];
        st->top--;
    }

    return x;
}

int Peek(struct Stack st, int position)
{
    int x = -1;

    if(st.top - position + 1 < 0 || position <= 0)
        printf("Invalid Position");
    else
        x = st.S[st.top - position + 1];

    return x;
}



int isEmpty(struct Stack st)
{
    if(st.top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack st)
{
    if(st.top == st.size - 1)
        return 1;
    else
        return 0;
}

int stackTop(struct Stack st)
{
    if(isEmpty(st))
        return -1;
    else
        return st.S[st.top];
}

int main()
{
    struct Stack st;
    Create(&st);

    Push(&st, 10);
    Push(&st, 20);
    Push(&st, 30);
    Push(&st, 40);
    Push(&st, 50);

    Display(st);

    printf("%d", stackTop(st));

    return 0;
}