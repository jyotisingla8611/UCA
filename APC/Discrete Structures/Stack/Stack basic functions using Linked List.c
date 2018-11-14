#include<stdio.h>
#include<stdlib.h>
typedef struct NODE {
    int data;
    struct NODE *next;
}node;

typedef struct stack {
    node *top;
}STK;

node *create_node() {
    node *new_nn = (node *)malloc(sizeof(node));
    return new_nn;
}

int isEmpty(STK *s) {
    if(s->top == NULL)
        return 1;
    return 0;
}

int isFull(STK *s,int size) {
    if(s->top == size)
        return 1;
    return 0;
}

void push(STK *s,int d) {
    node *n = create_node();
    n->data = d;
    n->next = s->top;
    s->top = n;
}
int pop(STK *s) {
    if(isEmpty(s))
        return -1;
    node *ptr = s->top;
    int res = ptr->data;
    s->top = ptr->next;
    free(ptr);
    return res;
}
int peek(STK *s) {
    return s->top->data;
    node *ptr = s->top;
    return ptr->data;
}

void print(STK *s) {
    node *ptr = s->top;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
int main() {
    STK *strt;
    strt = (STK *)malloc(sizeof(STK));
    strt->top = NULL;
    int size;
    scanf("%d",&size);
    int i;
    int num;
    for(i=0;i<size;i++){
        scanf("%d",&num);
        push(strt,num);
    }
    print(strt);
    printf(" \n%d is popped out ",pop(strt));
    printf(" \n%d is at peek ",peek(strt));
    print(strt);
}
