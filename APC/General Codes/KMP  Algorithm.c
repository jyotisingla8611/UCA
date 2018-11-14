#include<stdio.h>
#include<string.h>
void K_M_P(string str1,string str2){
   int i = 0 ;
   int j = 1;
   int lps[strlen(str2)];
   for(i=0;i<str2[i]!='\0';){
      if(str2[i]==str2[j]){
        lps[j]=i+1;
        i++;
        j++;
      }
      else{
       if(i==0){
        lps[j]=0;
        j++;
        }
       if(i!=0){
        i = lps[i-1];
       }
    }
   }
}
