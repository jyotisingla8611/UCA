#include<stdio.h>
void reduceSequence(char *str, char ch)
{
  char res[19];
  int i,j,k=0,c=0;
  for(i=0;i<str[i] != '\0';i++){
    c=0;
    if(str[i]==ch){
      for(j=i+1;j<str[j] != '\0';j++){
        if(str[j]==ch)
          c++;
          else
            break;
      }
    }
    res[k++]=str[i];
     i=i+c;
  }
  res[k]='\0';
  printf("%s",res);
}
int main(){
    char a[]="aabbcdeaaaaaabd";
    char ch = 'a';
    reduceSequence(a,ch);
}
