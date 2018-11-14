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
/*SinglyLinkedListNode * redundant(SinglyLinkedListNode *listHead){
    SinglyLinkedListNode *ptr = listHead;
    SinglyLinkedListNode *ptr1,*curr,*res;
    while(ptr->next != NULL && ptr != NULL){
            ptr1 = ptr;
           // res = ptr;
        while(ptr1->next != NULL){
            if(ptr->data == ptr1->next->data){
                    curr = ptr1->next;
                ptr1->next = ptr1->next->next;
            free(curr);
            }
            else{
                ptr1 = ptr1->next;
            }
        }
        ptr = ptr->next;
      //  res = res->next;
    }
   // res = NULL;
    return listHead;
}*/
SinglyLinkedListNode* distinct(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *ptr = head;
    SinglyLinkedListNode *ptr1,*temp,*curr;
    while( ptr != NULL && ptr->next != NULL){
        ptr1 = ptr;
        while(ptr1 != NULL && ptr1->next != NULL ){
            if(ptr->data == ptr1->next->data){
                temp = ptr1->next;
                ptr1->next = ptr1->next->next;
               // ptr1 = ptr1->next;
                free(temp);
            }
            else{
               ptr1 = ptr1->next;
            }
        }
        ptr = ptr->next;
    }
    return head;
}

int main(){
    SinglyLinkedListNode *head = NULL;
    AtBeg(&head,5);
    AtBeg(&head,4);
    AtBeg(&head,2);
    AtBeg(&head,1);
    AtBeg(&head,4);
    AtBeg(&head,3);
    AtBeg(&head,2);
    AtBeg(&head,4);
    printList(head);
    printf("\n The result is : \n");
    SinglyLinkedListNode *new_n = distinct(head);
    printList(new_n);
}

