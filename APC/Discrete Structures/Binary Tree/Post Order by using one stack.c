#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct stack
{
    struct node* tt;
    struct stack* next;
};
struct node* newnode(int data)
{
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}
void push(struct stack** ss,struct node* n)
{
    struct stack* nn=(struct stack*)malloc(sizeof(struct stack));
    nn->tt=n;
    nn->next=(*ss);
    (*ss)=nn;
}
struct node* pop(struct stack** stk)
{
    struct stack* ss;
    ss=*stk;
    struct node* nn;
    nn=ss->tt;
    (*stk)=ss->next;
    free(ss);
    return nn;
}
int empty(struct stack* stk)
{
    if(stk == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct node* peek(struct stack* stk)
{
    struct node* nn=stk->tt;
    return nn;
};
void postOrder(struct node* root)
{
    struct node* curr=root;
    struct stack* stk=NULL;
    while(curr||!empty(stk))
    {
    if(curr!=NULL)
    {
        push(&stk,curr);
        curr=curr->left;
    }
    else
    {
        struct node* temp=peek(stk)->right;
        if(temp == NULL)
        {
            temp=pop(&stk);
            printf("%d ",temp->data);
            while(!empty(stk)&&temp == peek(stk)->right)
            {
                temp=pop(&stk);
                printf("%d ",temp->data);
            }
        }
        else
        {
            curr=temp;
        }
    }
    }
}
int main()
{
    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    postOrder(root);
    return 0;
}
