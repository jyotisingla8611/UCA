#include<bits/stdc++.h>
using namespace std;
typedef struct btree{
    int data;
    struct btree *left,*right;
}bt;

queue<bt*>q;

bt* create(int d){
    bt* nn = (bt*)malloc(sizeof(bt));
    nn->data = d;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

void insert(bt **root,int d){
    bt *head;
    bt *temp = create(d);
    if(*root == NULL){
        *root = temp;
        q.push(temp);
    }
    else{
        if(!q.empty())
            head = q.front();
        if(!head->left)
        {
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
    inOrder(root->left);
        printf("%d ",root->data);
    inOrder(root->right);
}

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
int main(){
    bt *root = NULL;
    insert(&root,1);
    insert(&root,2);
    insert(&root,3);
    insert(&root,4);
    insert(&root,5);
    insert(&root,6);
    insert(&root,7);
    insert(&root,8);
    insert(&root,9);
    insert(&root,10);
    inOrder(root);
    int h = height(root);

    printf("\nHeight is : %d ",h);
}
