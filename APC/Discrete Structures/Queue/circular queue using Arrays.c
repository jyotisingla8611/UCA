#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int front, rear;
    int *arr;
};
void initialize(struct queue *mem, int len)
{
   // mem->size = 0;
    mem -> front = -1;
    mem -> rear = -1;
    mem -> arr = (struct queue*)malloc(sizeof(struct queue) * len);
}
int isEmpty(struct queue *mem)
{
    if(mem->front == -1 && mem->rear == -1)
        return 1;
    return 0;
}
int isFull(struct queue *mem, int len)
{
    if(mem->rear == len)
        return 1;
    return 0;
}
void enqueue(struct queue *mem, int data)
{
    if((mem->rear + 1)%5 == mem->front)
    {
        return 0;
    }
    else if(isEmpty(mem) == 1)
    {
        mem->front = mem->front + 1;
        mem -> rear = mem -> rear + 1;
    }
    else
    {
        mem -> rear = (mem -> rear + 1)%5;
    }
        mem->arr[mem->rear] = data;
        //mem->size = mem->size + 1;
        printf("%d\n", data);
}
int dequeue(struct queue *mem)
{
    if(isEmpty(mem) == 1)
        return 0;
    else if(mem->front == mem->rear)
    {
        mem->front = -1;
        mem->rear = -1;
    }
    else
    {
        mem->front = (mem->front + 1) % 5;
    }
}
int front(struct queue *mem)
{
    return mem->arr[mem->front];
}
int rear(struct queue *mem)
{
    return mem->arr[mem->rear];
}
int main()
{
    struct queue *q = (struct queue*)malloc(sizeof (struct queue) * 1000);
    initialize(q, 5);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    dequeue(q);
    printf("front %d\n", front(q));
    printf("rear %d\n",rear(q));
}
