#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

char pop(Stk *s) {
    if(empty(s))
        return -1;
    return s->arr[s->top--];
}

char peek(Stk *s) {
    return s->arr[s->top];
}

void check(Stk *ss,char *str,int len) {
    int i;
    for(i=0;i<len;i++) {
        if(str[i] == '{' || str[i] == '[' || str[i]=='(')
            push(ss,str[i]);
        if(str[i]==')'){
            if(peek(ss)=='(')
                pop(ss);
        }
        if(str[i]=='}'){
            if(peek(ss)=='{')
                pop(ss);
        }
        if(str[i]==']'){
            if(peek(ss)=='[')
                pop(ss);
        }
    }
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
    Stk *ss;
    ss = malloc(sizeof(Stk));
    char str[30];
    gets(str);
    int len = strlen(str);
    int i;
    init(ss,len);
    check(ss,str,len);
    if(empty(ss))
        printf("Given string is balanced parenthesis");
    else
        printf("Given string is Not balanced parenthesis");
}
