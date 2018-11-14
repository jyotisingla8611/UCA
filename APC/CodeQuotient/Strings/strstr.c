#include<stdio.h>
int strstrCode(char *src, char *str)
{
    int i, j, firstOcc;
   i = 0, j = 0;
   while (src[i] != '\0') {
      while (src[i] != str[0] && src[i] != '\0')
         i++;
      if (src[i] == '\0')
         return (-1);
      firstOcc = i;
      while (src[i] == str[j] && src[i] != '\0' && str[j] != '\0') {
         i++;
         j++;
      }
      if (str[j] == '\0')
         return (firstOcc);
       i = firstOcc + 1;
      j = 0;
   }
}
int main() {
   int loc;
   char source[] = "CodeQuotient";
   char target[] = "ent";
   loc = strstrCode(source, target);
   printf("%d",loc);
}
