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
// To Insert an element at first location
void AtBeg(Node** head_ref,int d){
    Node *n = create_Nodes(); //New Node Created
    n->data = d; // Data is assigned to new node
    n->next = *head_ref; // New Node will point to head address
    *head_ref = n;
}

void insertAfter( Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
      printf("the given previous node cannot be NULL");
      return;
    }
    Node* new_node =create_Nodes();
    new_node->data  = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append( Node** head_ref, int new_data)
{
    Node* new_node = create_Nodes();
    Node *current = *head_ref;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = new_node;
    return;
}

void FromBeg(Node** head_ref){
    Node *temp = *head_ref;
    if(*head_ref == NULL)
    {
        printf("Node is already Empty \n ");
        return;
    }
    else{
        // *temp = *head_ref;
        *head_ref= temp->next;
        int d = temp->data;
        free(temp);
        temp = NULL;
    }
}

void FromEnd(Node** head_ref){
    Node *curr = *head_ref,*temp;
    if(*head_ref == NULL)
        return;
    else{
        while( curr->next->next!=NULL){
            curr=curr->next;
        }
        temp=curr->next;
        curr->next=NULL;
        free(temp);
    }
}

void DeleteAtPos(Node** head_ref,int pos){
    Node *temp = *head_ref,*curr = NULL;
    int i=1;
    if(*head_ref == NULL)
        return;
    if(pos == 1){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    else{
    while(temp != NULL && pos-1 != i){
        i++;
        temp = temp->next;
    }
    curr = temp->next;
    temp->next = temp->next->next;
    free(curr);
}
}
void printList(Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}

int main(){
      Node *head = NULL;
      AtBeg(&head, 7);
      AtBeg(&head, 1);
      insertAfter(head,4);
      append(&head,6);
      append(&head,11);
      append(&head,12);
      insertAfter(head->next,12);
      printf("Node has elements : \n");
      printList(head);
      FromBeg(&head);
      printf("\nAfter deleting a front node we get : \n");
      printList(head);
      FromEnd(&head);
      printf("\nAfter deleting a end node we get : \n");
      printList(head);
      DeleteAtPos(&head,5);
      printf("\nAfter deleting a position of a node we get : \n");
      printList(head);
      return 0;
}
