/*
Sample Input 2

programming
Sample Output 2

gnimmargorp

*/
#include<stdio.h>
int count(char *s){
  int i,c=0;
  for(i=0;i<s[i]!='\0';i++)
    c++;
  return c;
}
void swap(char *a ,char *b){
  char c;
  c=*a;
  *a=*b;
  *b=c;
}
void reverseString (char str[])
{
 int i,len;
  len = count(str);
  for(i=0;i<len/2;i++){
    swap(&str[i],&str[len-1-i]);
  }
}
int main() {
      char s[100];
    gets(s);
  reverseString(s);
  puts(s);
}
