#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
typedef struct btree {
    char data;
    struct btree* left;
    struct btree* right;
}btree;
btree* newNode(char data)
{
    btree* node = (btree*)malloc(sizeof(btree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int checktree(btree *A , btree *B){
    if(A&&B){
        if(A->data != B->data)
            return 0;
        return(checktree(A->left,B->left) && checktree(A->right , B->right));
    }
    if(A == NULL && B == NULL)
        return 1;
    return 0;
}

int main(){
    btree *root = NULL;
    root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    btree *root1 = NULL;
    root1 = newNode(1);
    root1->left        = newNode(2);
    root1->right       = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5);
    if(checktree(root,root1))
        printf("Identical");
    else
        printf("Non Identical");
}
