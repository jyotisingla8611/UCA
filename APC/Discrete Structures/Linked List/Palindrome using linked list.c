#include<stdio.h>
typedef struct node{
    int data;
    struct node *next;
}Node;

void printList(Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}
int palindrome(Node **head_ref, Node *head){
    if(head==NULL)
        return 1;
    else{
        int y = palindrome(head_ref,head->next);
        if(y==1){
            if((*head_ref)->data == head->data){
                *head_ref=(*head_ref)->next;
                return 1;
            }
        }
        else
            return 0;
    }
}

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
  int res = palindrome(&head,head);
  if(res==1)
    printf("Palindrome");
  else
    printf("Not Palindrome");
  return 0;
}

