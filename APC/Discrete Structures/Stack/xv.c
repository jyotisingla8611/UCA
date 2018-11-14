void print(int a[],int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void PossiblePaths(struct node* root,int a[],int len)
{
    if(!root)
        return;
    a[len]=root->data;
    len++;
    if(root->left==NULL&&root->right==NULL)
    {
        print(a,len);
    }
    PossiblePaths(root->left,a,len);
    PossiblePaths(root->right,a,len);

}
