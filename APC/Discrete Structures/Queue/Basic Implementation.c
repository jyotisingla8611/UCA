#include<stdio.h>
#include<stdlib.h>
typedef struct qu {
    int *arr;
    int head;
    int tail;
}queue;
void initialise(queue * q,int size)
{
    q->arr = (int*)malloc(sizeof(int)*size);
    q->head=0;
    q->tail=-1;
}
int isFull(queue*q,int size)
{
    if(q->head==size)
        return 1;
    return 0;
}
int isEmpty(queue*q)
{
    if(q->tail == -1)
        return 1;
    return 0;
}
void push(queue*q,int size,int data)
{
    if(isEmpty(q))
    {
        q->tail=0;
    }
    if(isFull(q,size))
    {
        printf("The list is already full\n");
        return;
    }
     q->arr[q->head]=data;
    (q->head)++;
}
void pop(queue*q,int size)
{
    if(isEmpty(q)||q->tail==size)
    {
        printf("The list is already empty\n");
        return;
    }
    (q->tail)++;
}
int main()
{
    queue * q =(queue*)malloc(sizeof(queue));
    int size = 7;
  //  scanf("%d",&size);
    initialise(q,size);
    pop(q,size);
    push(q,size,1);
    push(q,size,2);
    push(q,size,3);
    pop(q,size);
     push(q,size,4);
      push(q,size,5);
       push(q,size,6);
       pop(q,size);
        push(q,size,7);
    int i;
    for(i=q->tail;i<q->head;i++)
        printf("%d ",q->arr[i]);
return 0;
}
