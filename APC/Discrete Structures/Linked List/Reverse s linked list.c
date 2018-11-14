#include<stdio.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
// To create a New Node
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

void Reverse(Node *head_ref){
    if(head_ref == NULL)
        return head_ref;
    else{
        Reverse(head_ref->next);
        printf("%d ",head_ref->data);
    }
}

int main(){
  Node *head = NULL;
  int n,i,num;
  printf("Enter number of elemnets : ");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&num);
    append(&head,num);
  }
  printf("\n Created Linked list is: ");
  printList(head);
  printf("\n \n Reverse is : ");
   Reverse(head);
  return 0;
}
