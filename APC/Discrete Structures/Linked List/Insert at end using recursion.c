#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *next;
}Node;

Node* creat(){
    Node* n = (Node*)malloc(sizeof(Node));
    return n;
}
void Insert_at_end_rec(Node **h,int d){
   if(*h == NULL){
   Node *nn = creat();
   nn->next = NULL;
   nn->data = d;
   *h = nn;
   }
   else
    Insert_at_end_rec(&((*h)->next),d);
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
      Insert_at_end_rec(&head,20);
      Insert_at_end_rec(&head,30);
      Insert_at_end_rec(&head,40);
      Insert_at_end_rec(&head,50);
      Insert_at_end_rec(&head,60);
      Insert_at_end_rec(&head,70);
      printList(head);
}
