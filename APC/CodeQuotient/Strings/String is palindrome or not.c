/*
Sample Input

2
Coding
cooc
Sample Output

NO
YES
*/
#include<stdio.h>
int count(char *s){
  int i,c=0;
  for(i=0;i<s[i]!='\0';i++)
    c++;
  return c;
}
void isPalindrome(char *str)
{
  int len1 = count(str);
  int i=0,flag=1;
  int len = len1 - 1;
  while(i<len && len>0){
    if(str[i] != str[len]){
      flag=0;
      break;
    }
    i++;
    len--;
  }
  if(flag==0)
    printf("NO");
  else
    printf("YES");
}
int main() {
    char s[100];
    gets(s);
    isPalindrome(s);
}
