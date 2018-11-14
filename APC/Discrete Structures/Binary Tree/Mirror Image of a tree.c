#include<stdio.h>
#include<stdlib.h>
typedef struct btree{
    int data;
    struct btree *right,*left;
}btree;

btree* newNode(int d){
    btree *new_n = (btree*)malloc(sizeof(btree));
    new_n->data = d;
    new_n->left = NULL;
    new_n->right = NULL;
}

void inOrder(btree *root){
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

btree * mirror(btree *root){
    if(root == NULL)
        return NULL;
    btree * nn = (btree *)malloc(sizeof(btree));
    nn->data = root->data;
    nn->left = mirror(root->right);
        nn->right = mirror(root->left);

    return nn;
}

void mirror_it(btree *root){
    if(root == NULL)
        return;
    mirror_it(root->left);
    mirror_it(root->right);
    btree *temp = root->left;
    root->left = root->right;
    root->right = temp;
}
int main(){
    btree *root = NULL;
    root = newNode(1);
    root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  printf("In order of existing tree is as : \n");
  inOrder(root);
   root = mirror(root);
   printf("\n In order of mirror tree is as : \n");
  inOrder(root);
  mirror_it(root);
  printf("\n In order of mirror tree is as : \n");
  inOrder(root);
}
