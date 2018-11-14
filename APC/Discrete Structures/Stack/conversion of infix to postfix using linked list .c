#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
    char data;
    struct NODE*next;
}node;
typedef struct stack
{
    node*top;
}STK;
char*peek(STK*s)
{
    return (s->top->data);
}
node*createNode()
{
    node*nn = (node*)malloc(sizeof(node));
    nn->next=NULL;
    return nn;
}
int isEmpty(STK * s)
{
    if(s->top==NULL)
        return 1;
    return 0;
}
void push(STK * s,char d)
{
    node*nn = createNode();
    nn->data=d;
    nn->next=s->top;
    s->top=nn;
}
char pop(STK * s)
{
    if(isEmpty(s))
        return '-1';
    node *temp = s->top;
    char d = temp->data;
    s->top = (s->top->next);
    free(temp);
    temp=NULL;
    return d;

}
int prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

void conversion(char *str)
{
    STK * s=(STK*)malloc(sizeof(STK));
    s->top=NULL;
    int len=strlen(str);
    int i;
    for(i=0;i<len;i++)
    {
        if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<'Z')
            printf("%c",str[i]);
        else if(str[i]=='(')
        {
            push(s,str[i]);
        }
        else if(str[i]==')')
        {

            while(peek(s)!='(')
            {
                printf("%c",pop(s));
            }
            pop(s);
        }
        else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^')
        {
            while(!isEmpty(s)&&(prec(str[i])<=prec(peek(s))))
                printf("%c",pop(s));
            push(s,str[i]);
        }
    }
}
int main()
{
    char str[100];

    scanf("%s",&str);

    conversion(str);
return 0;
}
