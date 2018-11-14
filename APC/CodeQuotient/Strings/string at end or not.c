#include<stdio.h>
int strAtEnd(char *str1, char* str2)
{
  int i=0,j=0,start,count1=0,count2=0;
  while(str2[i] != '\0'){
    count2++;
    i++;
  }
  i=0;
  while(str1[i] != '\0'){
    count1++;
    i++;
  }
  start = count1 - count2;
  printf("%d %d %d",count1,count2,start);
  while(start<count1){
        printf("\n %c %c \n",str1[start],str2[j]);
    if(str1[start]!=str2[j++])
      return 0;
  start++;
  }
  return 1;
}
int main() {
   int loc;
   char source[] = "CodeQuotient";
   char target[] = "ent";
   loc = strAtEnd(source, target);
   printf("%d",loc);
}
