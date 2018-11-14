#include<bits/stdc++.h>
typedef struct btree{
    int data;
    struct btree *right,*left;
}bt;

bt* insert(bt* root,int item){
    if(root == NULL){
        bt *nn = (bt*)malloc(sizeof(bt));
        nn->data = item;
        nn->left = NULL;
        nn->right = NULL;
        return nn;
    }
    if(item < root->data)
        root->left = insert(root->left,item);
    else if(item > root->data)
        root->right = insert(root->right,item);
    return root;
}

void inOrder(bt *root){
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

int main(){
    bt* root = NULL;
    root = insert(root,5);
    root = insert(root,7);
    root = insert(root,2);
    root = insert(root,9);
    root = insert(root,4);
    root = insert(root,8);
    root = insert(root,3);
    root = insert(root,6);
    //root = insert(root,1);
    inOrder(root);
}
