#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root=NULL;

int NodeHeight(struct Node *p)
{
    int LeftSubtreeHeight, RightSubtreeHeight;
    LeftSubtreeHeight = p && p->lchild ? p->lchild->height : 0;
    RightSubtreeHeight = p && p->rchild ? p->rchild->height : 0;

    return LeftSubtreeHeight > RightSubtreeHeight ? LeftSubtreeHeight + 1 : RightSubtreeHeight + 1;
}

int BalanceFactor(struct Node *p)
{
    int LeftSubtreeHeight, RightSubtreeHeight;
    LeftSubtreeHeight = p!=NULL && p->lchild != NULL ? p->lchild->height : 0;
    RightSubtreeHeight = p!=NULL && p->rchild != NULL ? p->rchild->height : 0;

    return LeftSubtreeHeight - RightSubtreeHeight;
}

struct Node * LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;

    return pl;
}

struct Node * LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if(root == p)
        root = plr;

    return plr;
}

struct Node* RecursiveInsert(struct Node *p, int key)
{
    struct Node *temp = NULL;

    if(p == NULL)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = key;
        temp->height = 1;
        temp->lchild = temp->rchild = NULL;
        return temp;
    }

    if(key < p->data)
        p->lchild = RecursiveInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = RecursiveInsert(p->rchild, key);

    p->height = NodeHeight(p);
    //Imbalance is on the left hand side and LL Rotation should be performed
    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) 
        return LLRotation(p);
    ////Imbalance is on the left hand side and to the right so LR Rotation should be performed
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    ////Imbalance is on the right hand side and RR Rotation should be performed
    //else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    //    return RRRotation(p);
    ////Imbalance is on the right hand side and to the left RL Rotation should be performed
    //else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    //    return RLRotation(p);
    return p;
}

int main()
{
    root = RecursiveInsert(root, 50);
    RecursiveInsert(root,10);
    RecursiveInsert(root,20);
    

    return 0;
}