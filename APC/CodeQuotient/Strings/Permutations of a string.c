// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));

          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack

       }
   }
}

int main()
{
    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}


/*
#include<string.h>
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void reverseString (char str[])
{
 int i,len;
  len = strlen(str);
  for(i=0;i<len/2;i++){
    swap(&str[i],&str[len-1-i]);
  }
}
void sort_alpha(char array1[])
{
    int num1[26] = {0}, i = 0,j=0;
    char res[26];
    while (array1[i] != '\0')
    {
        num1[array1[i] - 'a']++;
        i++;
    }
    for(i=0;i<26;i++){
        if(num1[i]>1)
        {
            while(num1[i]){
                res[j++]=i+'a';
                num1[i]--;
            }
        }
        if(num1[i]!=0){
            res[j++]= i+'a';
        }
    }
}
void permutations(char *s, int n)
{    sort_alpha(s);

    while (1)
    {
        printf("%s ",s);
        int i = n - 1;
        while (s[i-1] >= s[i])
        {
            if (--i == 0)
                return;
        }
        int j = n - 1;
        while (j > i && s[j] <= s[i - 1])
            j--;
        swap(&s[i - 1], &s[j]);
        reverseString(s);
    }
}
void printPermute(char *str)
{
  int len  = strlen(str);
  permutations(str,len);
}

*/
