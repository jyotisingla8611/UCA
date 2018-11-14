/* infix to prefix
   reverse a string(given)
   calculate infix to postfix
   reverse the result of 2nd operation
*/
#include<stdio.h>
typedef struct stack{
 char *a;
 int top;
 }stk;
 void initialize(stk *t,int n)
 {
  t->a = (char*)malloc(sizeof(char)*n);
  t->top = -1;
 }
 int isEmpty(stk *s){
     if(s->top == -1)
        return 1;
    return 0;
 }
void push(stk *s,char num,int n)
{
    if(isfull(s,n))
    {
        printf("can't insert any more element");
    }
    else
    {
        s->top++;
        s->a[s->top] = num;
    }
}
int isfull(stk* s,int n)
{
    if(s->top == n)
        return 1;
    return 0;
}
char pop(stk *s)
{
    char d = s->a[s->top];
    (s->top)--;
    return d;
}
int comp(char ch)
{
    if(ch=='(')
        return 0;
    else if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='*'||ch=='/')
        return 2;
    else if(ch == '^')
        return 3;
}
void infixtopostfix(char str[50])
{
//    printf("%s\n",str);
    stk *s=(stk*)malloc(sizeof(stk));
    int n=strlen(str);
    initialize(s,n);
    int i;
    char res[50]="";
    int k=0;
    for(i=0;i<n;i++)
    {
        if(str[i]=='(')
        {
            push(s,str[i],n);

        }
        else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/' || str[i] == '^')
        {
                while( !isEmpty(s) && comp(s->a[s->top])>=comp(str[i])){
                   res[k++] = pop(s);
                }
                push(s,str[i],n);

        }
        else if(str[i]==')') {
            char x;
            while((x = pop(s)) != '(')
                    res[k++] = x;
        }
        else
            res[k++]=str[i];
    }
    while(s->top != -1) {
        res[k++] = pop(s);
    }
    res[k] = '\0';
    printf("%s\n",res);
}
 int main()
 {
 char str[50];
 int test;
 printf("Enter number of testcases \n");
 scanf("%d",&test);
 while(test--){
 scanf("%s",str);
 infixtopostfix(str);
 }
 return 0;
}

