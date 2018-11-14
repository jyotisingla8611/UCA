#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500

struct btree
{
    int data;
    struct btree* left;
    struct btree* right;
}bt;

struct btree** createQueue(int *, int *);
void enQueue(struct btree **, int *, struct btree *);
struct btree *deQueue(struct btree **, int *);

void printLevelOrder(struct btree* root)
{
    int rear, front;
    struct btree **queue = createQueue(&front, &rear);
    struct btree *temp_btree = root;

    while (temp_btree)
    {
        printf("%d ", temp_btree->data);

        /*Enqueue left child */
        if (temp_btree->left)
            enQueue(queue, &rear, temp_btree->left);

        /*Enqueue right child */
        if (temp_btree->right)
            enQueue(queue, &rear, temp_btree->right);

        /*Dequeue btree and make it temp_btree*/
        temp_btree = deQueue(queue, &front);
    }
}

/*UTILITY FUNCTIONS*/
struct btree** createQueue(int *front, int *rear)
{
    struct btree **queue =
        (struct btree **)malloc(sizeof(struct btree*)*MAX_Q_SIZE);

    *front = *rear = 0;
    return queue;
}

void enQueue(struct btree **queue, int *rear, struct btree *new_btree)
{
    queue[*rear] = new_btree;
    (*rear)++;
}

struct btree *deQueue(struct btree **queue, int *front)
{
    return queue[(*front)++];
}

/* Helper function that allocates a new btree with the
   given data and NULL left and right pointers. */
struct btree* newbtree(int data)
{
    struct btree* btree = (struct btree*)
                        malloc(sizeof(struct btree));
    btree->data = data;
    btree->left = NULL;
    btree->right = NULL;
    return(btree);
}

/* Driver program to test above functions*/
int main()
{
    struct btree *root = newbtree(1);
    root->left        = newbtree(2);
    root->right       = newbtree(3);
    root->left->left  = newbtree(4);
    root->left->right = newbtree(5);

    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);

    return 0;
}
