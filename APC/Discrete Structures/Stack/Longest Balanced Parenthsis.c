#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef struct stack {
    char *arr;
    int top;
}Stk;

void init(Stk *s,int val) {
    s->arr = malloc(sizeof(char)*val);
    s->top = -1;
}

int empty(Stk  *s) {
    if(s->top == -1)
        return 1;
    return 0;
}
void push(Stk *s,int data) {
    s->top++;
    s->arr[s->top] = data;
}
int pop(Stk *s) {
    if(empty(s))
        return -1;
    return s->arr[s->top--];
}
int peek(Stk *s) {
    return s->arr[s->top];
}

int check(Stk *ss,char *str) {
    int i;
    int count=0;
    int max = 0;
    int len = strlen(str);
    for(i=0;i<len;i++) {
        if(str[i] == '{' || str[i] == '[' || str[i]=='('){
            push(ss,str[i]);
        }
        if(str[i]==')'){
            if(peek(ss)=='(')
                pop(ss);
            else
                ss->top=0;
        }
        if(str[i]=='}'){
            if(peek(ss)=='{')
                pop(ss);
            else
                ss->top=0;
        }
        if(str[i]==']'){
            if(peek(ss)=='[')
                pop(ss);
            else
                ss->top=0;
        }
        if(empty(ss))
            max = i;
    }
    return max+1;
}
void display(Stk *s)
{
    int i;
    if(s->top > 0){
    for(i=s->top;i>=0;i--)
        printf("%d ",s->arr[i]);
    }
    else {
        printf("Stack is empty");
    }
}
int main() {
    int res = 0;
    Stk *ss;
    ss = malloc(sizeof(Stk));
    char str[30];
    gets(str);
    int len = strlen(str);
    int i;
    init(ss,len);
        res = check(ss,str);

    printf("Longest Balanced Parenthesis is %d",res);
}

