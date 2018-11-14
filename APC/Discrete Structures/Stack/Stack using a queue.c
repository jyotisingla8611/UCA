#include<stdio.h>
#include<stdlib.h>
typedef struct stack {
    int top;
    int *arr;
}Stk;

typedef struct queue {
    int head;
    int tail;
    int *arr;
    int count;
}Que;

void init_queue(Que *q , int size) {
    q->arr = (int*)malloc(sizeof(int)*size);
    q->head = 0;
    q->tail = -1;
    q->count = 0;
}

int isEmpty_queue(Que *q) {
    if(q->tail == -1)
        return 1;
    return 0;
}

int isFull_queue(Que *q , int size) {
    if(q->head == size)
        return 1;
    return 0;
}

void enqueue(Que *q , int data ,int size) {
    if(isFull_queue(q,size)) {
        printf("Queue is already full \n");
        return;
    }
    q->arr[q->head++] = data;
    q->count++;
}

int dequeue(Que *q , int size) {
    if(isEmpty_queue(q) || q->tail == size)
    {
        printf("Queue is already empty \n");
        return;
    }

    q->count--;
    q->tail++;
    return q->arr[q->tail];
}

int queue_size(Que *q) {
    return(q->count);
}

void init_stack(Stk *s,int size) {

    s->arr = (int*)malloc(sizeof(int)*size);
    s->top = -1;
}

void push(int val,Que *q,int size) {
    printf("as");
    int n = queue_size(q);
    printf("qu sizee %d ",n);
    int i = 0;
    enqueue(q,val,size);
 /*   for(i=0;i<n;i++)
        enqueue(q,dequeue(q,size),size);*/
    int x = dequeue(q,size);
}

int stack_top(Que *q , int size) {
    if(isEmpty_queue(q)) {
        printf("Stack is empty \n");
        return;
    }
    else
        return dequeue(q,size);
}

void display_stack(Que *q , int size) {
    printf("%d ",stack_top(q,size));
}

int main() {
    Stk *s = (Stk*)malloc(sizeof(Stk));
    Que *q = (Que*)malloc(sizeof(Que));
    int size;
    int i = 0;
    int num;
    printf("Enter Size \n");
    scanf("%d",&size);
    init_queue(q,size);
    init_stack(s,size);
    printf("Enter Numbers \n");
    for(i=0;i<size;i++) {
        scanf("%d",num);
        push(num,q,size);
    }
    display_stack(q,size);
}
