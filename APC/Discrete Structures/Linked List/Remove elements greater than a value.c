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
SinglyLinkedListNode* removeNodes(SinglyLinkedListNode* listHead, int x) {
  /*  SinglyLinkedListNode *ptr = listHead;
    SinglyLinkedListNode *temp,*curr = listHead,*prev;
    while(ptr->data > x){
        listHead = listHead->next;
        ptr = listHead;
    }
    while(ptr != NULL ){
        while(ptr->data <= x){
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = ptr->next;
        free(ptr);
        ptr = prev->next;
    }
    return listHead;*/
    SinglyLinkedListNode *curr = listHead ,*temp = listHead->next;
    while(listHead->data > x)
        listHead = listHead->next;
    curr = listHead;
    temp = listHead->next;
    while(temp){
        if(temp->data > x){
            curr->next = temp->next;
            temp = curr->next;
        }
        else{
            temp = temp->next;
            curr = curr->next;
        }
    }
    return listHead;
}

int main(){
    SinglyLinkedListNode *head = NULL;
    AtBeg(&head,5);
    AtBeg(&head,5);
    AtBeg(&head,2);
    AtBeg(&head,3);
    AtBeg(&head,1);
    printList(head);
    printf("\n The result is : \n");
    SinglyLinkedListNode *new_n = removeNodes(head,2);
    printList(new_n);
}
