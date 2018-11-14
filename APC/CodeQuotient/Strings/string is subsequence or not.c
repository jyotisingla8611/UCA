#include<stdio.h>
int count(char *s){
    int i=0,c=0;
    while(s[i]!=0){
        i++;
        c++;
    }
return c;
}
void strSubsequence(char *str, char* match )
{
   int flag=0,i,j;
   int len1 = count(str);
   int len2 = count(match);
   for(i=0,j=0;i<len1&&j<len2;i++){
    if(str[i]==match[j])
        j++;
   }
   if(j==len2)
    flag=1;
   if(flag==0)
     printf("NO\n");
   else
    printf("YES\n");
}

int main() {
   char source[] = "CodeQuotient";
   char target[] = "CQ";
   strSubsequence(source, target);

}
