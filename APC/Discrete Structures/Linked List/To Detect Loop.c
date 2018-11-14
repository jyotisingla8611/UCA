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

void detect(Node **head){
    Node *fastptr = *head,*slowptr = *head,*temp = *head;
    while(temp != NULL){
        printf(" %d %d \n",fastptr->next->next->data,slowptr->next->data);
        if(fastptr->next->next == slowptr->next){
            printf("Hence loop exists \n ");
            return;
            break;
        }
        temp = temp->next;
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
    }
    //printf("Loop Does Not exist \n ");
}

void loop(Node **head)
{
    Node *temp = *head,*curr = NULL,*ptr=*head;
    int c=0;
    while(temp!= NULL)
    {
      c++;
      if(c==3)
      {
          break;
      }
      temp=temp->next;
    }
    while(ptr!=NULL)
    {
        curr=ptr;
        ptr=ptr->next;
    }
   // printf("%d ",temp->data);
    curr->next=temp;
   // printf("%d value is joining",curr->next->data);
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
    int n,num,i;
    Node *head = NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        append(&head,num);
    }
   // detect(&head);
   //
    loop(&head);
    detect(&head);
}
