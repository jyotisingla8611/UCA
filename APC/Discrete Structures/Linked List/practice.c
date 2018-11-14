#include<stdlib.h>
#include<stdio.h>
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
    if(node == NULL){
        printf("List is Empty \n ");
    }
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}
//To deleten whole linked list
void Delete_List(Node **head_ref){
    Node *temp = *head_ref,*next_node;
    while(temp != NULL){
        next_node = temp->next;
        free(temp);
        temp = next_node;
    }
    *head_ref = NULL;
}
//To find length of linked list(ITERATION METHOD_)
int length(Node **head_ref){
    Node *temp = *head_ref;
    int count=0;
    while(temp != NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
//To find length of linked list(RECURSION METHOD_)
int recursive_count(Node *head){
    if(head == NULL)
        return 0;
    else
        return 1 + recursive_count(head->next);
}
//TO search a node value (ITERATION METHOD)
int search_key(Node **head,int key){
    Node *ptr = *head;
    int i=0;
    while(ptr != NULL){
            i++;
        if(ptr->data == key){
            return i;
        }
        ptr = ptr->next;
    }
    return -1;
}
//To search node value (RECURSION METHOD)
int rec_search(Node *head,int key){
    static int i=0;
    if(head == NULL)
        return -1;
    if(head->data == key){
            i++;
        return i;
    }
    else{
        i++;
        return rec_search(head->next,key);
    }
}
//To get value of node at a position (ITERATION METHOD)
int get_node_val(Node **head,int pos){
    int c=0;
    if(*head == NULL){
        printf("List is empty \n");
        return;
    }
    Node *curr = *head;
    while(curr != NULL){
        c++;
        if(c==pos){
            return (curr->data);
            break;
        }
        curr = curr->next;
    }
    return -1;
}
//To get value of node at a position (RECURSION METHOD)
int get_nth_node(Node *head,int pos){
    if(pos>length(&head))
    {
        printf("\n Not a valid position \n");
        return -1;
    }
    int count=0;
    if(count++ == pos)
        return (head->data);
    else
        return (head->next,pos);
}

void printNthFromLast( Node* head, int n)
{
    int len=0 , i;
     Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    if (len < n){
     printf(" \nThis location is beyond the length \n");
     return;
    }
    temp = head;
    for (i = 1; i < len-n+1; i++)
    temp = temp->next;

    printf ("%d is value at %d from last", temp->data,n);

    return;
}
int main(){
    int n,i,num;
    Node *head = NULL;
    printf("Enter number of elements u wanna add \n ");
    scanf("%d",&n);
    printf("Enter the elements : \n");
    for(i=0;i<n;i++){
        scanf("%d",&num);
        append(&head,num);
    }
    printf("The list is as : \n");
    printList(head);
    //printf("\nAfter deleting whole list we get : \n");
    //Delete_List(&head);
    //printList(head);
    int res,key,key1;
    res = length(&head);
    printf("\nThe length of a node is : %d \n",res);
    printf("\nThe length of a node is : %d \n",recursive_count(head));
    printf("\nEnter key u want to search : \n");
    scanf("%d",&key);
    int search_res = search_key(&head,key);
    if(search_res==-1)
        printf("\nElement not found \n");
    else
        printf("\nElement is found at %d \n",search_res);
    printf("\nEnter key u want to search : \n");
    scanf("%d",&key1);
    int search_res1 = rec_search(head,key1);
    if(search_res1==-1)
        printf("\nElement not found \n");
    else
        printf("\nElement is found at %d \n",search_res1);
    printf("Enter position whose value u wanna fetch \n");
    int pos;
    scanf("%d",&pos);
    int resultant = get_node_val(&head,pos);
    if(resultant==-1)
        printf("\n Position does not exist \n");
    else
        printf("\nValue is %d \n",resultant);
    printf("Enter position whose value u wanna fetch \n");
    int pos1;
    scanf("%d",&pos1);
    int x = get_nth_node(head,pos1);
    if(x>0)
    printf("\nValue is %d \n",x);
    int y;
    printf("\nEnter location from end whose value u wanna get \n");
    scanf("%d",&y);
    printNthFromLast(head,y);

}
