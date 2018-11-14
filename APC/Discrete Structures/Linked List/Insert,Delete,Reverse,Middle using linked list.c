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

void printList(Node *head){
    while(head != NULL){
    printf(" %d ", head->data);
     head = head->next;
    }
}

void AtBeg(Node **head,int value){
    Node *new_node = create_Nodes();
    new_node->next = *head;
    new_node->data = value;
    *head = new_node;
}

void AtEnd(Node **head,int value){
    Node *new_node = create_Nodes();
    Node *curr = *head;
    new_node->next = NULL;
    new_node->data = value;
    if(*head == NULL){
        *head = new_node;
        return;
    }
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = new_node ;
        return;
}

void AfterLoc(Node **head,int value,int pos){
    Node *new_node = create_Nodes();
    Node *curr = *head;
    Node *temp = NULL;
    int i=1;
    new_node->data = value;
    if(*head == NULL){
        printf("Insertion is not posssible \n ");
        return ;
    }
    while(curr->next != NULL){
        if(i++ == pos){
            break;
        }
        curr = curr->next;
    }
    new_node->next=curr->next;
    curr->next=new_node;
}

void DelAtBeg(Node **head){
    Node *temp = *head;
    if(*head == NULL){
        printf("List is already empty ..LOL\n");
        return;
    }
    *head = temp->next;
    free(temp);
}

void DelAtEnd(Node **head){
    Node *curr = *head,*temp = *head;
    while(curr->next->next != NULL){
        curr=curr->next;
    }
    temp=curr->next;
    curr->next = NULL;
    free(temp);
}

void DelAtLoc(Node **head,int pos){
    int i=1;
    Node *curr = *head;
    Node *temp = *head;
    if(*head == NULL){
        return ;
    }
    if(pos == 1){
        *head = temp->next;
        free(temp);
        return;
    }
    while(curr->next != NULL){
        if(i == pos-1){
            break;
        }
        curr=curr->next;
        i++;
    }
    temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
}

Node *Rev(Node *head){
    if(head == NULL)
        return head;
    else{
        Rev(head->next);
        printf("%d ",head->data);
    }

}
int Middle(Node **head){
    Node *fast = *head,*slow = *head;
    while(fast->next && fast->next->next){
        fast = (fast->next)->next;
        slow = slow->next;
    }
    return slow->data;

c}

int main(){
    Node *head = NULL;
    int ch,value,pos;
    char choice;
    printf("You cannot proceed furthur without pressing 1 \n");
    printf("1.Insert a Node \n");
    printf("2.Delete a Node \n");
    printf("3.Reverse a Node \n");
    printf("4.Find middle value of list \n");
    printf("To exit -1\n");
    printf("Enter choice\n");
    scanf("%d",&ch);
    while(ch != -1){
    switch(ch)
    {
    case 1:
        printf("a.To insert at beg \n");
        printf("b.To insert at end \n");
        printf("c.To insert after a location \n");
        printf("Enter choice\n");
        scanf("%s",&choice);
        printf("Enter value \n");
        scanf("%d",&value);
        switch(choice)
        {
        case 'a':
            AtBeg(&head,value);
            printf("After inserting at begin  :");
            printList(head);
            printf("\n");
            break;
        case 'b':
            AtEnd(&head,value);
            printf("After inserting at end  : ");
            printList(head);
            printf("\n");
            break;
        case 'c':
            printf("Enter position \n");
            scanf("%d",&pos);
            AfterLoc(&head,value,pos);
             printf("After inserting after a location  :  ");
             printList(head);
             printf("\n");
        }
        break;
    case 2:
        printf("d.To delete at beg \n");
        printf("e.To delete at end \n");
        printf("f.To delete at a location \n");
        scanf("%c",&choice);
        switch(choice)
        {
        case 'd':
            DelAtBeg(&head);
             printf("After deleting at begining: ");
            printList(head);
            printf("\n");
            break;
        case 'e':
            DelAtEnd(&head);
             printf("After deleting at end :  ");
            printList(head);
            printf("\n");
            break;
        case 'f':
           // int pos;
            printf("Enter position \n");
            scanf("%d",&pos);
            DelAtLoc(&head,pos);
            printf("After deleting a particular location :  ");
            printList(head);
            printf("\n");
        }
        break;
    case 3:
         printf("Reverse of list is as  : ");
         Node *result = Rev(head);
         printf("\n");
         break;
    case 4:
         printf("Mid value is : %d \n",Middle(&head));
    }
    printf("Enter choice again if u wanna : ");
    scanf("%d",&ch);
    }
}
