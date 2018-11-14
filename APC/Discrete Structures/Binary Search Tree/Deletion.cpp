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

int findmax(bt *root){
    while(root->right)
        root = root->right;
    return root->data;
}

bt* del(bt* root , int item){
    if(root->data == item){
        if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
            return root->left;
        else{
            int x = findmax(root->left);
            root->data = x;
            root->left = del(root->left,x);
            return root;
        }
    }
    if(root->data > item)
        root->left = del(root->left,item);
    else if(root->data < item)
        root->right = del(root->right,item);
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
    root = del(root,5);
    //root = insert(root,1);
    inOrder(root);
}
