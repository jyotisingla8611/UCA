
#include<bits/stdc++.h>
using namespace std;
typedef struct btree
{
  int data;
  struct btree* left;
  struct btree* right;
}bt;
bt* insert(bt* root, int item)
{
  if(root==NULL)
  {
    bt* nn= (bt*)malloc(sizeof(bt));
    nn->data = item;
    nn->left = NULL;
    nn->right = NULL;
   return nn;
  }
  if(item<root->data)
   root->left = insert(root->left, item);
  else if(item>root->data)
   root->right = insert(root->right, item);
   return root;
}
int findMax(bt* root)
{
    while(root->right)
    root=root->right;
    return root->data;
}
bt* delNode(bt* root, int item)
{
    if(root->data==item)
      {
        if(root->left==NULL)
           return root->right;
        else if(root->right==NULL)
           return root->left;
        else
         {
           int x = findMax(root->left);
           root->data = x;
           root->left = delNode(root->left, x);
           return root;
         }
      }
    if(root->data>item)
      root->left = delNode(root->left, item);
   else if(root->data<item)
 root->right = delNode(root->right, item);
    return root;
}
void inOrder(bt* root)
{
   if(root==NULL)
     return;
   inOrder(root->left);
   printf("%d ",root->data);
   inOrder(root->right);
}
int main()
{
     bt* root = NULL;
  root=insert(root, 5);
  root=insert(root, 7);
  root=insert(root, 2);
  root=insert(root, 9);
  root=insert(root, 4);
  root=insert(root, 8);
  root=insert(root, 3);
  root=insert(root, 6);
  root=delNode(root, 4);
  inOrder(root);
}
