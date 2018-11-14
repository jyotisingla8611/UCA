#include<bits/stdc++.h>
using namespace std;
typedef struct btree{
    int data;
    struct btree *right;
    struct btree *left;
}bt;

queue<bt*>q;

bt* create_node(int d){
    bt *nn = (bt*)malloc(sizeof(bt));
    nn->data = d;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

void insert(bt **root , int value){
    bt *head;
    bt *temp = create_node(value);
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
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

void preOrder(bt*root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(bt *root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}

stack<bt*>st;

void inOrder_it(bt *root){
    bt *curr = root;
    while(curr != NULL || st.empty() == false){
        while(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}

void preOrder_it(bt *root){
    bt *curr = root;
    while(curr != NULL || st.empty() == false){
        while(curr != NULL){
            cout<<curr->data<<" ";
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        curr = curr->right;
    }
}

void postorder_it(bt *root){
    bt* curr=root;
    while(curr|| st.empty() == false)
    {
    if(curr!=NULL)
    {
        st.push(curr);
        curr=curr->left;
    }
    else
    {
        bt* temp = st.top()->right;
        if(temp == NULL)
        {
            temp= st.top();
            st.pop();
            printf("%d ",temp->data);
            while(st.empty() == false && temp == st.top()->right)
            {
                temp = st.top();
                st.pop();
                printf("%d ",temp->data);
            }
        }
        else
        {
            curr=temp;
           // printf("\n ** curr %d",curr->data);
        }
    }
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
    cout<<"In Order Recursive : ";
    inOrder(root);
    cout<<endl<<endl<<"Pre Order Recursive : ";
    preOrder(root);
    cout<<endl<<endl<<"Post Order Recursive : ";
    postOrder(root);
    cout<<endl<<endl<<"In Order Iterative : ";
    inOrder_it(root);
    cout<<endl<<endl<<"Pre Order Iterative : ";
    preOrder_it(root);
    cout<<endl<<endl<<"Post Order Iterative : ";
    postorder_it(root);
}
