#include<stdio.h>
char* comp1(void *x,void *y){
    return *((char*)x) - *((char*)y);
}
void remDuplicates(char *arr)
{
    qsort(arr,strlen(arr),sizeof(char),comp1);
    int i,j=0;
  for(i=0;i<arr[i]!='\0';i++){
    if(arr[i]!=arr[i+1])
      arr[j++]=arr[i];
  }
  arr[j]='\0';
}
int main(){
    char a[100];
    gets(a);
    remDuplicates(a);
    puts(a);
}
