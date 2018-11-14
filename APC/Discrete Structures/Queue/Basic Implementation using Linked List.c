#include<stdio.h>
#include<stdlib.h>
typedef struct n {
    int data;
    struct n *next;
}node;
typedef struct q {
    node* head;
    node* tail;
}queue;
node * createnode()
{
    node*nn = (node*)malloc(sizeof(node));
    nn->next=NULL;
    return nn;
}
queue * createqueue()
{
    queue * q = (queue*)malloc(sizeof(queue));
    q->head=NULL;
    q->tail=NULL;
    return q;
}
void push(queue*q,int d)
{
    node*nn = createnode();
    nn->data=d;
    if(q->head==NULL)
    {
        q->head=nn;
        q->tail=nn;
        return;
    }
    else{
    q->head->next=nn;
    q->head=nn;
    }
}
int pop(queue*q)
{
    if(q->head==NULL&&q->tail==NULL)
    {
        printf("Queue is already empty");
        return;
    }
    int d = q->tail->data;
    q->tail = q->tail->next;
    if(q->tail==NULL)
        q->head=NULL;
    return d;
}
int main()
{
    queue * q = createqueue();
    //pop(q);
    push(q,20);
    push(q,30);
    push(q,50);
    push(q,90);
   // pop(q);
    //pop(q);
    pop(q);
   // pop(q);
    node*curr;
    curr=q->tail;
    while(curr)
    {
        printf("%d ",curr->data);
        curr=curr->next;
    }
return 0;
}
