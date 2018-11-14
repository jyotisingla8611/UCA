/*
1. itoa() function converts int data type to string data type.
2. atoi() function converts string data type to int data type.

Sample Input
"100" 135

Sample Output

100 "135"
*/

#include<stdio.h>
void itoa(int num, char* result)
{
    int rem,count=0,num1=num,len,i=0;
     while(num){
       count++;
       num = num/10;
     }
  result[count]='\0';
  len = count-1;
  while(num1){
    rem = num1%10;
    result[len--] = rem + '0';
    num1 = num1/10;
  }
}
int atoi(char *str)
{
  int res = 0;
  int i;
    for ( i = 0; str[i] != '\0'; ++i)
        res = res*10 + str[i]-'0';
    return res;
}
int main(){
    char s[100];
    int n;
    gets(s);
    scanf("%d",&n);
    int res = atoi(s);
    char s1[100];
    itoa(n,s1);
    printf("%d ",res);
    printf("\"%s\"",s1);
}
