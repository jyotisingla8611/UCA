#include<stdio.h>
#include<string.h>
int areRotations(char *str1, char *str2)
{
  int size1   = strlen(str1);
  int size2   = strlen(str2);
  char *temp;
  void *ptr;
 if(size1 != size2)
     return 0;
  temp   = (char *)malloc(sizeof(char)*size1*2 + 1);
  temp[0] = '\0';
  strcat(temp, str1);
  strcat(temp, str1);
  ptr = strstr(temp, str2);
  if(ptr != NULL)
    return 1;
  else
    return 0;
}

int main()
{
    char *str1 = "ABCD";
    char *str2 = "BCDA";
    if(areRotations(str1, str2))
       printf("Strings are rotations of each other");
    else
       printf("Strings are not rotations of each other");
    return 0;
}
