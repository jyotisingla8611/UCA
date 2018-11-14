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

void inorder_morris(btree *root){
    btree *curr , *pre;
    if(root == NULL){
        return;
    }
    curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            printf("%d ",curr->data);
            curr = curr->right;
        }
        else{
            pre = curr->left;
            while(pre->right != NULL && pre->right != curr )
                pre = pre->right;
            if(pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                printf("%d ",curr->data);
                curr = curr->right;
            }
        }
    }
}

void preorder_morris(btree *root){
    if(root == NULL)
        return;
    btree *curr, *pre;
    curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            printf("%d ",curr->data);
            curr = curr->right;
        }
        else{
            pre = curr->left;
            while(pre->right != NULL && pre->right != curr)
                pre =pre->right;
            if(pre->right == NULL){
                pre->right = curr;
                printf("%d ",curr->data);
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                curr = curr->right;
            }
        }
    }
}

int main(){
    btree *root = NULL;
    root = newNode(1);
    root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  inorder_morris(root);
  printf("\n");
  preorder_morris(root);
}
