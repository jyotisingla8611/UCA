#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}SinglyLinkedListNode;
    SinglyLinkedListNode *create_node(){
    SinglyLinkedListNode *nn=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    return nn;
}
void AtBeg(SinglyLinkedListNode **head_ref ,int d){
    SinglyLinkedListNode *newSinglyLinkedListNode = create_node();
    newSinglyLinkedListNode->data = d;
    newSinglyLinkedListNode->next = *head_ref;
    *head_ref = newSinglyLinkedListNode;
}
void printList(SinglyLinkedListNode *SinglyLinkedListNode)
{
  while (SinglyLinkedListNode != NULL)
  {
     printf(" %d ", SinglyLinkedListNode->data);
     SinglyLinkedListNode = SinglyLinkedListNode->next;
  }
}
SinglyLinkedListNode * swap_l(SinglyLinkedListNode *listHead,int x,int y){
    SinglyLinkedListNode *ptr = listHead;
    SinglyLinkedListNode *ptr1,*curr,*res;
    while(ptr != NULL){
        int temp = x;
        if(ptr->data == x)
            ptr->data = y;
        else if(ptr->data == y)
            ptr->data = x;
        ptr = ptr->next;
    }
return listHead;
}
int main(){
    SinglyLinkedListNode *head = NULL;
    AtBeg(&head,78);
    AtBeg(&head,22);
    AtBeg(&head,43);
    AtBeg(&head,48);
    AtBeg(&head,98);
    printList(head);
    printf("\n The result is : \n");
    SinglyLinkedListNode *new_n = swap_l(head,78,98);
    printList(new_n);
}

