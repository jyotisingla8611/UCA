#include<stdio.h>
#include<stdlib.h>
typedef struct n
{
    int data;
    struct n*next;
}node;
typedef struct st
{
    node*top;
}stack;
node*createnode()
{
    node*nn=(node*)malloc(sizeof(node));
    nn->next=NULL;
    return nn;
}
int isEmpty(stack * s)
{
    if(s->top==NULL)
        return 1;
    return 0;
}
void push(stack * s,int d)
{
    node*nn = createnode();
    nn->data=d;
    nn->next=s->top;
    s->top=nn;
}
int pop(stack * s)
{
    if(isEmpty(s))
        return -1;
    node*temp=s->top;
    int d = temp->data;
    s->top = (s->top->next);
    free(temp);
    temp=NULL;
    return d;
}
int * comp1(void*x,void*y)
{
    return *(int*)x - *(int*)y;
}
int size;
int main()
{
    while (scanf("%d", &size) && size != 0) {

    int arr[size];
    int i;
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    stack*s = (stack*)malloc(sizeof(stack));
    s->top=NULL;
    int sorted[size];
    for(i=0;i<size;i++)
        sorted[i]=arr[i];
    qsort(sorted,size,sizeof(int),comp1);
    int j=0;
    for(i=0;i<size;)
    {
        if(arr[i]==sorted[j])
         {   i++;
            j++;
        }
        else
        {
                if(!isEmpty(s)&&s->top->data==sorted[j])
                {
                    pop(s);
                    j++;
                }
                else
                {
                    push(s,arr[i]);
                    i++;
                }
        }
    }
    if(j==size)
    {    printf("yes\n");
        continue;
    }
    else
    {
        while(!isEmpty(s)&&j<size)
        {
            int d = pop(s);
            if(d==sorted[j])
            {
                j++;
            }
            else
                break;
        }
    }
    if(j==size)
        printf("yes\n");
    else
        printf("no\n");

    }
return 0;
}

