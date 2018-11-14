#include<stdio.h>
int countWords(char str[])
{
    int i=0,c=0;
  while(str[i]!='\0')
  {
      if(str[i]==' ')
        c++;
        i++;
  }
  if(str[i]=='\0' && str[i-1]==' ')
    return c;
  return(c+1);
}
int main()
{
    char arr[100]="Codequotient get better at coding ";
    int res = countWords(arr);
    printf("%d",res);
}
