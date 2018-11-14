#include <stdio.h>
#include <stdlib.h>
typedef struct btree {
    char data;
    struct btree* left;
    struct btree* right;
}btree;
btree* newNode(char data)
{
    btree* node = (btree*)malloc(sizeof(btree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int search1(char arr[], int strt, int end, char value)
{
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
}

btree* buildTree(char in[], char pre[], int strt, int end)
{
    static int preIndex = 0;
    if (strt > end)
        return NULL;
    btree* temp = newNode(pre[preIndex++]);
    if (strt == end)
        return temp;
    int inIndex = search1(in, strt, end, temp->data);
    temp->left = buildTree(in, pre, strt, inIndex - 1);
    temp->right = buildTree(in, pre, inIndex + 1, end);

    return temp;
}

void printInorder(btree* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%c ", node->data);
    printInorder(node->right);
}
int main()
{
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
    btree* root = buildTree(in, pre, 0, len - 1);
    printf("Inorder traversal of the constructed tree is \n");
    printInorder(root);
    getchar();
}
