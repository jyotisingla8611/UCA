/*
Sample Input

2
aabbcdeaaaaaabd a
xyzxyzxyz x
Sample Output

abbcdeabd
xyzxyzxyz
*/
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
  i=0;
  while(res[i]!='\0'){
    str[i] = res[i];
    i++;
  }
  str[i]='\0';
}
int main() {
    char s[100];
    gets(s);
    char ch;
    scanf("%c",&ch);
    reduceSequence(s,ch);
    puts(s);
}
