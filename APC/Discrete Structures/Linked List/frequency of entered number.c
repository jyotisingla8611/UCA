#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;

Node* create_Nodes(){
    Node* n = (Node*)malloc(sizeof(Node));
    return n;
}

void append(Node **head_ref,int value){
    Node *new_node = create_Nodes();
    new_node->data = value;
    Node *current = *head_ref;
    new_node->next = NULL;
    if(*head_ref == NULL){
        *head_ref=new_node;
        return;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = new_node;
    return;
}
int count(Node **head_ref,int findval){
    Node *curr = *head_ref;
    int count=0;
    while(curr != NULL){
        if(curr->data == findval)
            count++;
        curr = curr->next;
    }
    return count;
}
int main(){
    Node *head = NULL;
    append(&head,1);
    append(&head,2);
    append(&head,3);
    append(&head,4);
    append(&head,1);
    append(&head,6);
    append(&head,8);
    append(&head,1);
    append(&head,1);
    printf("Enter value to be searched \n");
    int val;
    scanf("%d",&val);
    int res = count(&head,val);
    if(res!=0)
    printf("Number of times it come is %d",res);
    else
        printf("Oops Number has not found\n");
}
