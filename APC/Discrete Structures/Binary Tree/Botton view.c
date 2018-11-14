#include<stdio.h>

#include<string.h>
typedef struct btree
{
    int data;
    int hd; /*horizontal distance*/
    struct btree* left;
    struct btree* right;
}btree;

typedef struct queue
{
    btree* node[100];
    int front;
    int rear;
}queue;

void initializeQueue(queue* q)
{
    int i;
    for(i=0;i<100;i++)
    {

        q->node[i] = NULL;
    }
    q->front=-1;
    q->rear=-1;
}


int isEmpty(queue* q)
{
            if(q->front == -1 && q->rear==-1)
            {
                return 1;
            }
            return 0;
}
void addElement(queue* q, btree* root)
{

        q->rear = (q->rear +1)%100;
        q->node[q->rear] = root;
        if(q->front ==-1)
        {
            q->front = q->rear;
        }


}

btree* poll(queue* q)
{
   btree* root = q->node[q->front];

        if(q->front== q->rear)
        {
           q->front= q->rear=-1;

        }
        else
            {

            q->front = (q->front +1)%100;
            }


    return root;
}


btree* initializeNode(int d, int hdist)
{
    btree* nn = (btree*)malloc(sizeof(btree));
    nn->data = d;
    nn->left = NULL;
    nn->right = NULL;
    nn->hd = hdist;
    return nn;
}
int res[200];

btree* createTree(btree* root, int d, int hd)
{
    if( root == NULL)
    {
        return initializeNode(d, hd);
    }

    if( d  < root-> data)
    {

        root->left  = createTree(root->left, d, hd-1);
    }
    else
        root->right  = createTree(root->right, d,hd+1);

    return root;
}

void bottomView( btree* root,  int* l, int* r)
{
    queue obj;
    initializeQueue(&obj);
    addElement(&obj,root);
    while(!isEmpty(&obj))
    {

        btree* root = poll(&obj);
        if(root->left)
        {
            addElement(&obj,root->left);
        }
        if(root->right)
        {
            addElement(&obj,root->right);
        }
        printf("%d----%d\n", root->data, root->hd);
            res[root->hd+100] = root->data;
                if(*l> (root->hd+100))
                    *l = root->hd+ 100;
                if(*r< ( root->hd+ 100))
                    *r = root->hd+100;
    }
}

int main()
{
memset(res,0,100*sizeof(res[0]));
    btree* root = NULL;

    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
        root = createTree(root, arr[i],0);
    }
int left=100,right=100;
bottomView(root,&left,&right);

for(i=left;i<=right;i++)
    {
    printf("%d ", res[i]);
    }

}
