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

Node *Merge(Node *h1,Node *h2){
    Node *res = NULL;
    if(h1==NULL)
        return h2;
    if(h2==NULL)
        return h1;
    if(h1->data <= h2->data){
        res = h1;
        res->next = Merge(h1->next,h2);
    }else{
        res = h2;
        res->next = Merge(h1,h2->next);
    }
    return res;
}
int main(){
    int n,n1,i,num;
    Node *head = NULL;
    Node *head1 = NULL;
    printf("Enter number of elements u wanna add in list1 \n ");
    scanf("%d",&n);
    printf("Enter the elements : \n");
    for(i=0;i<n;i++){
        scanf("%d",&num);
        append(&head,num);
    }
    printf("Enter number of elements u wanna add in list2 \n ");
    scanf("%d",&n1);
    printf("Enter the elements : \n");
    for(i=0;i<n1;i++){
        scanf("%d",&num);
        append(&head1,num);
    }
    printf("The list1 is as : \n");
    printList(head);
    printf("\nThe list2 is as : \n");
    printList(head1);
    Node *final = Merge(head,head1);
    printf("\nThe merged list is as : \n");
    printList(final);
}
