#include<stdio.h>
#include<stdlib.h>
typedef struct stack {
    int *arr;
    int top;
}STK;
void initialise(STK *mem,int x) {
    mem->arr = (int*)malloc(sizeof(int)*x);
    mem->top = -1;
}
int isEmpty(STK *s) {
    if(s->top == -1)
        return 1;
    return 0;
}
int isFull(STK *s,int size) {
    if(s->top == size)
        return 1;
    return 0;
}
void push(STK *s , int d) {
    {
        s->top++;
        s->arr[s->top] = d;
    }
}
int pop(STK *s)
{
    if (isEmpty(s))
        return 1;
    int x = s->arr[s->top--];
    return x;
}
void display(STK *s)
{
    int i;
  /*  if(s->top > 0){
    for(i=s->top;i>=0;i--)
        printf("%d ",s->arr[i]);
    }*/
    i = s->top;
    while(i != -1){
        printf("%d ",s->arr[i]);
        i--;
    }
}
int peek(STK *s) {
    return s->arr[s->top];
}

int main() {
    STK *strt;
    strt = (STK *)malloc(sizeof(STK));
    int size;
    scanf("%d",&size);
    initialise(strt,size);
    int i;
    int num;
    for(i=0;i<size;i++){
        scanf("%d",&num);
        push(strt,num);
    }
    display(strt);
    printf(" \n%d is popped out ",pop(strt));
    printf(" \n%d is at peek\n ",peek(strt));
    display(strt);
}
