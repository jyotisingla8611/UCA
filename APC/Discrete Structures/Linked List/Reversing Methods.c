//To Reverse the List
#include<stdlib.h>
#include<stdio.h>
typedef struct node{
    int data;
    struct node *next;
}Node;

Node* create_Nodes(){
    Node* n = (Node*)malloc(sizeof(Node));
    return n;
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

void printList(Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}
void Reversing(Node  **head_ref){
    Node *ptr1 = NULL;
    Node *ptr2 = *head_ref;
    while(ptr2 != NULL){
        Node *ptr3 = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr3;
    }
    *head_ref = ptr1;
}

Node *Reverse_recursive(Node *first){
    Node *second;
    if(first)
        second = first->next;
    if(!second)
        return first;
    else{
        Node *current = Reverse_recursive(second);
        first->next = second->next;
        second->next = first;
        return current;
    }
}

int main(){
    int n,i,num;
    Node *head = NULL;
    printf("Enter number of elements u wanna add \n ");
    scanf("%d",&n);
    printf("Enter the elements : \n");
    for(i=0;i<n;i++){
        scanf("%d",&num);
        append(&head,num);
    }
    printf("The list is as : \n");
    printList(head);
    Reversing(&head);
    printf("\nAfter reversing a list \n");
    printList(head);
    Node *result = Reverse_recursive(head);
    printf("\nAfter reversing a list \n");
    printList(result);
    printf("\n Just to verify reverse the list again \n");
    Node *result1 = Reverse_recursive(result);
    printList(result1);
}
