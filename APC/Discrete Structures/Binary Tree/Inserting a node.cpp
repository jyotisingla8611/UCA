#include<bits/stdc++.h>
using namespace std;
typedef struct btree{
    int data;
    struct btree *right;
    struct btree *left;
}bt;

queue<bt*>q;

bt * create_node(int d){
    bt* new_node = (bt*)malloc(sizeof(bt));
    new_node->data = d;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(bt **root,int d){
    bt *head;
    bt *temp = create_node(d);
    if(*root == NULL){
        *root = temp;
        q.push(temp);
    }
    else{
        if(!q.empty())
            head = q.front();
        if(!head->left){
            head->left = temp;
            q.push(temp);
        }
        else if(!head->right){
            head->right = temp;
            q.push(temp);
        }
        if(head && head->left && head->right)
            q.pop();
    }
}

void inOrder(bt *root){
    if(root == NULL)
        return;
    printf("%d ",root->data);
    inOrder(root->left);
    inOrder(root->right);
}
int main(){
    bt *root = NULL;
    insert(&root,1);
    insert(&root,2);
    insert(&root,3);
    insert(&root,4);
    insert(&root,5);
    insert(&root,6);
    insert(&root,7);
    inOrder(root);
}
