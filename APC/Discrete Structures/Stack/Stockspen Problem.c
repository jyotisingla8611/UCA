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
void push(STK *s , int d) {
    if(s->top == -1){
        s->top++;
        s->arr[s->top] = d;
    }
    else
    {
        s->top++;
        s->arr[s->top] = d;
    }
}
int peek(STK *s) {
    return s->arr[s->top];
}
void pop(STK *s)
{
    if (isEmpty(s))
        return 1;
    s->top--;
}
void display(STK *s)
{
    int i;
    for(i=0;i<=s->top;i++)
        printf("%d ",s->arr[i]);
}
STK * stock(STK *s,int size) {
    STK *res1 ;
    res1 = (STK*)malloc(sizeof(STK));
    initialise(res1,size);
    push(res1,1);
    STK *st;
    st = (STK*)malloc(sizeof(STK));
    initialise(st,size);
    push(st,0);
    int i;
    for(i=1;i<size;i++) {
        while(!isEmpty(st) && s->arr[peek(st)] <= s->arr[i])
            pop(st);
        if(isEmpty(st))
            push(res1,i + 1);
        else
            push(res1,i - peek(st));
        push(st,i);
    }
    return res1;
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
    printf("The Stack is as : \n");
    display(strt);
    STK *res;
    res = (STK*)malloc(sizeof(STK));
    initialise(res,size);
    res = stock(strt,size);
    printf("\nThe span is as : \n");
    display(res);
}
