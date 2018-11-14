#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<limits.h>
struct Node {
  int data;
  struct Node *next;
};

int isEmpty(struct Node **head){
    return !head;
  }

  struct Node* createNode(int data){
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
  }

void push(struct Node **head,int data){
    struct Node* temp = createNode(data);
    temp->next = *head;
    *head = temp;
}

int pop(struct Node **head){
  if(isEmpty(head)){
      return INT_MIN;
  }

  struct Node *temp = *head;
  *head = (*head)->next;

  int data = temp->data;
  free(temp);
  return data;
}

int peek(struct Node **head){
  if(!isEmpty(head)) {
      return (*head)->data;
  }
  return INT_MIN;
}

int main(){
  struct Node *head  = NULL;

  push(&head, 20);
  push(&head, 50);
  push(&head, 70);

  assert(peek(&head) == 70);

  pop(&head);

  assert(peek(&head) == 50);

  return 0;
}
