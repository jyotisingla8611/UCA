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
void printmax(btree *root,int sum,int *max){
    if(root == NULL)
        return;
    sum = sum + root->data;
    if(root->left == NULL && root->right == NULL){
        if(sum > *max)
            *max = sum;
        return;
    }
    if(root->left)
        printmax(root->left,sum,max);
    if(root->right)
        printmax(root->right,sum,max);
}

int main(){
  btree *root = NULL;
  root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  int *max = INT_MIN;
  int sum = 0;
  printmax(root,sum,max);
  printf("%d is max ",max);
}
