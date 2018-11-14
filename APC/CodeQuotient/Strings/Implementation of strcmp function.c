/*
0        : if both strings are identical (equal)
Negative : if the ASCII value of first unmatched character in first string is less than second string.
Positive : if the ASCII value of first unmatched character in first string is greater than second string.
*/

#include<stdio.h>
int strcmp(const char *str1, const char *str2)
{
    int i=0,j=0,sum=0;
    while(str1[i] != '\0' || str2[i] != '\0'){
      if(str1[i] == str2[j])
         sum = sum;
      else if(str1[i]>str2[j])
      {
        sum = sum + (str1[i]-str2[j]);
        return sum;
      }
      else if(str1[i]<str2[j]){
        sum = sum + (str2[i]-str1[j]);
        sum = -sum;
        return sum;
      }
      i++;
      j++;
    }
  return sum;
}
int main() {
    char s[100];
    char s1[200];
    gets(s);
    gets(s1);
    int res = strcmp(s,s1);
    printf("%d",res);
}
