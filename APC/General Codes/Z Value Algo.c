#include<stdio.h>
#include<string.h>
int main(){
   char str1[100];
   char str2[100];
   gets(str1);
   gets(str2);
   int i=0,j=0,k=0,flag=0;
   int z[200];
   int l=0;
   int r=0;
   int len1 = strlen(str1);
   int len2 = strlen(str2);
   strcat(str2,"$");
   strcat(str2,str1);
   for(i=1;i<len1+len2+1;i++){
    if(i>r){
           l=i;
            r=i;
         while(r<len1+len2+1 && str2[r-l]==str2[r])
           r++;
        z[i]=r-l;
         r--;
      }
      else{
        if(z[i-l] < r-i+1)
         z[i] = z[i-l];
        else
        {
            l=i;
            r=i;
            while(r<len1+len2+1 &&str2[r-l]==str2[r])
           r++;
          z[i]=r-l;
            r--;
        }
      }
   }
   z[0]=0;
   for(i=0;i<len1+len2+1;i++)
    printf("%d ",z[i]);
}
