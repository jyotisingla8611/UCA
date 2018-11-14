#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
typedef struct trie trie;

struct trie{
  trie *arr[26];
  bool IsEndofword;
};

trie *createNode(){
    trie *nn = (trie*)malloc(sizeof(trie));
    int i;
    for(i=0;i<26;i++)
        nn->arr[i]=NULL;
    nn->IsEndofword = false;
    return nn;
}

void insert(trie *root,char *str){
    int i;
    for(i=0;i<strlen(str);i++){
        int j = str[i]-'a';
        if(root->arr[j]){
            root = root->arr[j];
        }
        else{
            root->arr[j] = createNode();
            root = root->arr[j];
        }
    }
    root->IsEndofword = true;
}

bool search(trie *root,char str[],int index){
    if(index == strlen(str)){
        if(!root->IsEndofword)
            return false;
        return true;
    }
    int j = str[index] - 'a';
    if(!root->arr[j])
       return false;
    return search(root->arr[j],str,index+1);
}

int main(){
    trie *root = createNode();
    char s[] = "hello";
    char s1[] = "hell";
    char s2[] = "world";
    char s3[] = "wore";
    insert(root,s);
    insert(root,s1);
    insert(root,s2);
    insert(root,s3);
    if(search(root,"hello",0))
        printf("Found");
    else
        printf("Not Found");
}
