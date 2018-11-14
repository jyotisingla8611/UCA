#include<stdio.h>
void strcatCode(char *str1, char *str2)
{
  int i=0,j=0;
  while(str1[i] != '\0')
    i++;
  while(str2[j] != '\0')
  {
    str1[i+j] = str2[j];
    j++;
  }
  str1[i+j] = '\0';
}
int main() {
    char s[100];
    char s1[200];
    gets(s);
    gets(s1);
    strcatCode(s,s1);
    puts(s);
}
