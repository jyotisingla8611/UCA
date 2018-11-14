#include<stdio.h>
#include<stdlib.h>
typedef struct btree{
    int d;
    struct btree * left;
    struct btree * right;
}btree;
btree * createNode(btree * root,int d){
    btree * node = (btree *)malloc(sizeof(btree));
    node->d = d;
    node->left = NULL;
    node->right = NULL;
    return node;
}
btree * ct(int * in,int * post,int s,int e,int * index){
    int i,ind;
    //static int index = e;If we do this error comes that initializer element is not constatnt
    // so address should be passed of index
    if(e<s){//if u know the condition in preorder then it can be changed while doing on the paper
        return NULL;
    }

    btree * nn = (btree *)malloc(sizeof(btree));

    nn->d = post[*index];
    //printf("pre is %d ",pre[index]);
    //if(s==e){
        //return nn;
    //}
    for(i=e;i>=s;i--){
        if(post[*index] == in[i]){
            break;
        }
    }
    ind = i;
    (*index)--;//to check the next number of postorder
    //Postorder - left right root so we have start from the root we now want right and then left
    nn->right = ct(in,post,ind+1,e,index);//Order of postorder is to be performed so right first
    nn->left = ct(in,post,s,ind-1,index);

    return nn;
}
void preorder(btree * root){//printing the preorder to check whether the tree constructed is right or not
if(root==NULL){
    return;
}
printf("%d ",root->d);
preorder(root->left);

preorder(root->right);

}
int main(){
    btree * root;
    int s,e,index;s=0;
    int in[7] = {4,2,5,1,6,3,7};
    int post[7] = {4,5,2,6,7,3,1};
    e=sizeof(in)/sizeof(in[0]);
    index = e-1;//index has to be the last as our root is last
    //printf("%d",e);
    root = ct(in,post,s,e-1,&index);
    preorder(root);
}


