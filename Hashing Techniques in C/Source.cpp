#include <stdio.h>
#include <stdlib.h>
#include "Chains.h"

int hash(int key)
{
    return key%10;    
}

void Insert(struct Node *H[], int key)
{
    int index = hash(key);
    SortedInsert(&H[index], key);
}

int main()
{
    int HT[10];

    return 0;
}