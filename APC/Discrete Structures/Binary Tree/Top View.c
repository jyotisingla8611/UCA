#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct queue{
    struct node*arr[50];
    int front;
    int rear;
};
struct node{
int data;
int hd;
struct node * left;
struct node * right;
};
struct queue * initialize(){
    int i;
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    for(i  = 0; i < 50; i++){
        q->arr[i] = NULL;
        q->front = -1;
        q->rear = -1;
    }
    return q;
}
int isEmpty(struct queue *q){                       //its not necessary to send address of queue bcz we are not changing anything
    if(q->front == -1 &&q ->rear == -1)
        return 1;
    else
        return 0;
}
void push(struct queue *q, struct node * root){
    if(q->rear == -1 && q->front == -1)
        q->front++;
      //printf("sbjx");

    q->rear++;
    q->arr[q->rear] = root;
}
struct node * poll(struct queue *q){
    struct node * temp = q->arr[q->front];
//++
    if(q->front == -1)
        printf("queue is empty \n");
    else{
        if(q->front == q->rear)
           {

            q->front = -1;
            q->rear = -1;
           }
        else
        {
           //struct node * temp = q->arr[q->front];
             q->front++;
            //return temp;
        }
        return temp;
    }

}
struct node* initializeNode(int d, int h){
    struct node * root = (struct node*)malloc (sizeof(struct node));
    root->data = d;
    root->hd = h;
    root->left = NULL;
    root->right = NULL;
}
struct node * createTree(struct node * root, int data, int hd){
    if(root == NULL){
        return initializeNode(data, hd);

    }
    if(data < root -> data)
    root->left = createTree(root->left, data, hd - 1);
    if(data > root -> data)
    root ->right = createTree(root->right, data, hd + 1);
    return root;
}

void topView(struct node * root,int *l,int *r){

    int arr[100],i ;

     for(i = 0; i< 100; i++)
    {
        arr[i] = 0;
    }
    printf("top view\n");

    struct queue *q=initialize();
    push(q, root);
    while(!isEmpty(q)){
       // printf("1");

        struct node *temp = poll(q);
        // printf("1587");
        if(temp->left){
            push(q,temp->left);
           // printf("          heloo  ");
        }
        if(temp->right){
            push(q, temp->right);
            //printf("          hiiiiiiiiiii  ");
        }
        if(arr[temp->hd +3] == 0)
        {
        arr[temp->hd + 3] = temp->data;
            if(*l > temp->hd + 3)
               *l = temp->hd + 3;
            if(*r < temp->hd + 3)
               *r = temp->hd + 3;
        }
    }

    printf(" l is as %d \n r is as %d \n",*l, *r);
    for(i = *l; i <= *r; i++)
    {
        printf("%d ",arr[i]);
    }

}
void inorder(struct node * root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf(" %d  ",root->data);
    inorder(root->right);

}
int main(){

    struct node * root = NULL;
    int arr[10];
    int i, n;
    for(i = 0; i < 3; i++){
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < 3; i++){
        root = createTree(root, arr[i], 0);
    }
  // inorder(root);
   int l =3;
   int r =3;
    topView(root,&l,&r);
   /* int ar[100] = {-1};
    for(i = 0; i< 100; i++)
    {
        printf("%d  ",ar[i]);
    }*/





}


/*#include<stdio.h>
#include<stdlib.h>
typedef struct binary
{
    int data;
    int hd;
    struct binary*left;
    struct binary*right;
}btree;
typedef struct n
{
    btree*ptr;
    struct n*next;
}node;
typedef struct qu
{
    node*head;
    node*tail;
}queue;
node*createnode()
{
    node*nn=(node*)malloc(sizeof(node));
    nn->next=NULL;
    return nn;
}
int isEmpty(queue*q)
{
    if(q->head==NULL&&q->tail==NULL)
        return 1;
    return 0;
}
void push(queue*q,btree*root)
{
    node*nn=createnode();
    nn->ptr=root;
    nn->next=NULL;
    if(isEmpty(q))
    {
        q->head=nn;
        q->tail=nn;
        return;
    }
    q->head->next=nn;
    q->head=nn;

}
btree*pop(queue*q)
{
    if(isEmpty(q))
        return NULL;
    btree*temp=q->tail->ptr;
    q->tail=q->tail->next;
    if(q->tail==NULL)
        q->head=NULL;
    return temp;
}
btree*createbtree(btree*root,int item)
{
    if( root == NULL)
    {
        btree* nn = (btree*)malloc(sizeof(btree));
        nn->data = item;
        nn->left = NULL;
        nn->right = NULL;
        return nn;
    }
    else if(item < root->data)
    {
        root->left = createbtree(root->left, item);
    }
    else
    {
        root->right = createbtree(root->right,item);
    }
    return root;
}
void inorder(btree*root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d\n",root->data);
    inorder(root->right);
}
int height(btree*root)
{
    if(root==NULL)
        return 0;
    int l=height(root->left);
    int r = height(root->right);
    return (l>r?(l+1):(r+1));
}
void topview(btree*root)
{
    queue*q=(queue*)malloc(sizeof(queue));
    q->head=NULL;
    q->tail=NULL;
    int h =height(root);
    int*arr=(int*)malloc(sizeof(int)*2*h);
    int i;
    for(i=0;i<2*h;i++)
        arr[i]=-1;
    if(root==NULL)
        return;
    push(q,root);
    while(!isEmpty(q))
    {
        btree*d=pop(q);
        int prevhd = d->hd;
        if(d->left)
        {
            push(q,d->left);
            d->left->hd=prevhd-1;
        }
        if(d->right)
        {
            push(q,d->right);
            d->right->hd = prevhd+1;
        }
        if(arr[prevhd+h]==-1)
            arr[prevhd+h]=d->data;
    }
    int j;
    printf("Top View is as : \n");
    for(j=0;j<2*h;j++)
    {
        if(arr[j]!=-1)
            printf("%d ",arr[j]);
    }
}
int main()
{
    int size;
    scanf("%d",&size);
    int arr[size];
    int i;
    btree*root=(btree*)malloc(sizeof(btree));
    root=NULL;
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
        root=createbtree(root,arr[i]);
    }
    inorder(root);
    topview(root);
}
*/
