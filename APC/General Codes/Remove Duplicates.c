#include<stdio.h>
char *comp1(void *x,void *y){
    return *((char*)x) - *((char*)y);
}
void removeDuplicates(char *arr)
{
  int i,j=0;
  for(i=0;i<arr[i]!='\0';i++){
    if(arr[i]!=arr[i+1])
      arr[j++]=arr[i];
  }
  arr[j]='\0';
}
int main()
{
    char arr[20]="aabdbcacbccdef";
    qsort(arr,strlen(arr),sizeof(char),comp1);
    removeDuplicates(&arr);
    int i;
    for(i=0;arr[i]!='\0';i++)
    printf("%c",arr[i]);
}
