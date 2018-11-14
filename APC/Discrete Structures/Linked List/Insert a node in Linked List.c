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
  // Insert 6.  So linked list becomes 6->NULL
  append(&head, 6);
  // Insert 7 at the beginning. So linked list becomes 7->6->NULL
  AtBeg(&head, 7);
  // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
  AtBeg(&head, 1);
  // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
  append(&head, 4);
  // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
  insertAfter(head, 8);
  printf("\n Created Linked list is: ");
  printList(head);
  return 0;
}
