/*
Sample Input

2
CodeQuotient
Coding


Sample Output

NO
YES
*/
#include<stdio.h>
void isUniqueChars(char *str)
{
  int i,j,flag=0;
  for(i=0;i<str[i] != '\0';i++){
    for(j=i+1;j<str[j] != '\0';j++){
      if(str[i]==str[j])
      {
        flag=1;
        break;
      }
    }
  }
  if(flag==1)
    printf("NO");
  else
    printf("YES");
}
int main() {
    char s[100];
    gets(s);
    isUniqueChars(s);
}
