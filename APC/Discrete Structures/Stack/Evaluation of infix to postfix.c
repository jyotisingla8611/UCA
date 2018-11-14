#include<ctype.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct stack{
 int *a;
 int top;
 }stk;
 void initialize(stk *t,int n)
 {
  t->a=(int*)malloc(sizeof(int)*n);
  t->top=-1;
 }
 int isEmpty(stk *s){
     if(s->top == -1)
        return 1;
    return 0;
 }
void push(stk *s,int num,int n)
{
    if(isfull(s,n))
    {
        printf("can't insert any more element");
    }
    else
    {
        s->top++;
        s->a[s->top]=num;
    }
}
int isfull(stk* s,int n)
{
    if(s->top==n)
        return 1;
    return 0;
}
int pop(stk *s)
{
    int d=s->a[s->top];
    (s->top)--;
    return d;
}
void postfix_evaluate(char *str)
{
    int n = strlen(str);
    int i = 0;
    stk *new_stack = (stk*)malloc(sizeof(stk));
    initialize(new_stack,n);
    int res;
    while(str[i] != '\0') {
        if(isdigit(str[i])){
            res = str[i]-'0';
        }
        else{
            int val1 = pop(new_stack);
            int val2 = pop(new_stack);
            switch(str[i]) {
            case '+':
                res = val1 + val2;
                break;
            case '-':
                res = val2 - val1;
                break;
            case '/':
                res = val1/val2;
                break;
            case '*':
                res = val1*val2;
                break;
            case '^':
                res = pow(val2,val1);
                break;
            }
        }
        push(new_stack,res,n);
        i++;
    }
    printf("%d is the required answer",pop(new_stack));
}
 int main()
 {
 char str[50];
 scanf("%s",str);
 postfix_evaluate(str);
}


/*
Value of 231*+9- is -4

*/
