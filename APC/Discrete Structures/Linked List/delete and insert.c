#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *next;
}Node;
Node *createnode(){
 Node *nn=(Node *)malloc(sizeof(Node));
 return nn;
}
void atend(Node **head,int value){
   Node *temp ,*curr = *head;
   temp=createnode();
   temp->data = value;
   temp->next = NULL;
   if(*head == NULL){
    *head = temp;
    return;
   }
   while(curr->next != NULL)
     {
        curr  = curr->next;
     }
    curr->next= temp;
}

void atbeg(Node **head,int value){
    Node *nn=createnode();
    nn->data = value;
    nn->next = *head;
    *head = nn;
}

void AtPos(Node **head,int value,int pos){
    Node *temp = createnode();
    Node *curr = *head , *prev;
    temp->data = value;
    int i=1;
    if(pos == 1)
    {
        atbeg(head,value);
        return;
    }
    while(curr->next != NULL){
          //  prev = curr;
        if(i==pos){
            break;
        }
        curr = curr->next;
        i++;
    }
    temp->next = curr->next;
    curr->next= temp;
}

void DeleteAtEnd(Node **head){
  Node *temp = *head , *curr;
 if(*head == NULL){
  return;
}
 while(temp->next->next != NULL){
    temp =temp->next;
}
curr = temp->next;
temp->next = NULL;
free(curr);
}

void DeleteAtBeg(Node **head){
    if(*head == NULL){
        return;
    }
    Node *temp = *head;
    *head = temp->next;
    free(temp);
}

void DeleteAtPos(Node **head,int pos){
    Node *curr = *head ,*temp;
    int i=1;
    if(pos == 1)
    {
        DeleteAtBeg(head);
        return;
    }
    while(curr->next != NULL){
        if(i==pos-1){
            break;
        }
        i++;
       curr = curr->next;
    }
    temp= curr->next;
    curr->next = curr->next->next;
    free(temp);
}

int searchval(Node **head,int key){
    Node *ptr = *head;
    int i=0;
    while(ptr != NULL){
        i++;
        if(ptr->data == key){
            return i;
        }
        ptr = ptr->next;
    }
    return 0;
}

void print(Node *head){
    if(head == NULL){
        printf("List is Empty \n");
        return;
    }
    printf("The linked list is :");
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
    return ;
}

int main()
{
Node *head = NULL;
int n,value,num,i;
scanf("%d",&n);
for(i=0;i<n;i++)
{
 scanf("%d",&num);
 atend(&head,num);
}
printf("Enter %d elements more too be added at begining \n",n);
for(i=0;i<n;i++){
    scanf("%d",&num);
    atbeg(&head,num);
}
int pos,val;
printf("enter postion \n ");
scanf("%d",&pos);
printf("Enter value \n");
scanf("%d",&val);
AtPos(&head,val,pos);
print(head);
printf("Enter position to be deleted \n ");
int p;
scanf("%d",&p);
DeleteAtPos(&head,p);
DeleteAtEnd(&head);
DeleteAtBeg(&head);
print(head);
int res,key_val;
printf("Enter key value to be searched \n");
scanf("%d",&key_val);
res = searchval(&head,key_val);
if(res!=0)
    printf("Key Value is found at %d \n",res);
else
    printf("Key Value is not found \n");
return 0;
}
