#include<stdio.h>
#include<stdlib.h>
typedef struct btree{
    int data;
    struct btree *right,*left;
}bt;
int height(bt *root){
    if(root == NULL)
        return 0;
    else{
        int l = height(root->left);
    int r = height(root->right);
    if(l>r)
        return (l+1);
    else
        return (r+1);
    }
}

int diameter(bt *root){
    if(root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return max(lh+rh+1,max(ld,rd));
}


int max(int a,int b){
    return (a>=b) ? a : b;
}

bt* newNode(int d){
    bt *new_n = (bt*)malloc(sizeof(bt));
    new_n->data = d;
    new_n->left = NULL;
    new_n->right = NULL;
}
int main(){
    bt *root = NULL;
    root = newNode(1);
    root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  printf("Diameter is %d",diameter(root));
}
