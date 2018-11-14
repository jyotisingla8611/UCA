#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *create_Nodes(){
    Node *nn=(Node *)malloc(sizeof(Node));
    return nn;
}
void AtBeg(Node **head_ref ,int d){
    Node *newnode = create_Nodes();
    newnode->data = d;
    newnode->next = *head_ref;
    *head_ref = newnode;
}
void atend(Node **head_ref,int d){
    Node *newnode = create_Nodes();
    Node *ptr = *head_ref;
    newnode->data = d;
    newnode->next = NULL;
    if(*head_ref == NULL){
        *head_ref = newnode;
        return ;
    }
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newnode ;
    return;
}
void swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void pairwise_swap(Node **head_ref){
    Node *ptr = *head_ref;
    Node *temp;
    while(ptr != NULL && ptr->next != NULL  ){
        temp = ptr->next;
        swap(&(ptr->data) , &(temp->data));
        ptr = ptr->next->next;
    }
}

void del_adjacent(Node **head_ref ){
    Node *ptr = *head_ref;
    Node *temp;
    while(ptr != NULL && ptr->next != NULL){
        temp = ptr->next;
        ptr->next = NULL;
        ptr->next = temp->next;
        temp->next = NULL;
        free(temp);
        ptr = ptr->next;
    }
}

void sort_ll(Node **head_ref){
    Node *ptr = *head_ref;
    Node *ptr1;
    while(ptr->next != NULL){
            ptr1 = ptr->next;
        while(ptr1 != NULL){
            if(ptr1->data < ptr->data)
                swap(&(ptr1->data),&(ptr->data));
            //else
                 ptr1 = ptr1->next;
        }
        ptr = ptr->next;
    }
}
void reversing(Node **head){
    Node *temp = NULL;
    Node *prev = NULL;
    Node *ptr = *head;
    while(ptr != NULL){
       temp = ptr->next;
       ptr->next = prev ;
       prev = ptr;
       ptr = temp;
    }
    *head = prev;
}
void printList(Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}

void even_odd(Node **head_ref){
    Node *ptr = *head_ref;
    printf("\nEven Numbers are as : \n");
    while(ptr != NULL){
        if(ptr->data % 2 == 0)
            printf(" %d ",ptr->data);
        ptr = ptr->next;
    }
    ptr = *head_ref;
    printf("\nOdd Numbers are as : \n");
    while(ptr != NULL){
        if(ptr->data % 2 != 0)
            printf(" %d ",ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    Node *head = NULL;
    AtBeg(&head,21);
    atend(&head,30);
    atend(&head,40);
    atend(&head,59);
    atend(&head,60);
    atend(&head,70);
    AtBeg(&head,10);
    AtBeg(&head,5);
    AtBeg(&head,7);
    AtBeg(&head,2);
    printf("the list is : \n");
    printList(head);
    reversing(&head);
    printf("\nThe reverse is : \n");
    printList(head);
    pairwise_swap(&head);
    printf("\nThe pairwise swap  is : \n");
    printList(head);
    del_adjacent(&head);
    printf("\nThe adjacent deletion results in : \n");
    printList(head);
    sort_ll(&head);
    printf("\nAfter sorting linked list we get : \n");
    printList(head);
    even_odd(&head);
}
