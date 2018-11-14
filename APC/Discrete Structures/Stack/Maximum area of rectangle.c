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

void pop(STK *s)
{
    if (isEmpty(s))
        return 1;
    s->arr[s->top--];
}

void display(STK *s)
{
    int i;
    if(s->top > 0){
    for(i=s->top;i>=0;i--)
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}

int peek(STK *s) {
    return s->arr[s->top];
}

int getMaxArea(STK *s1, int n)
{
     STK *s = (STK*)malloc(sizeof(STK));
    initialise(s,n);
    int max_area = 0; // Initalize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar
    int i = 0;
    while(i<n)
    {
        if (isEmpty(s) || s1->arr[peek(s)] <= s1->arr[i])
            push(s,i++);
        else
        {
            tp = peek(s);
            pop(s);
            area_with_top = s1->arr[tp] * (isEmpty(s) ? i :
                                   i - peek(s) - 1);
           if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
   while (isEmpty(s) == 0)
    {
        tp = peek(s);
        pop(s);
        area_with_top = s1->arr[tp] * (isEmpty(s) ? i :
                                i - peek(s) - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
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
    printf("The stack is as : \n");
    display(strt);
    int res = getMaxArea(strt,size);
    printf("\nMaximum area of rectangle in above stack is : %d",res);
}
