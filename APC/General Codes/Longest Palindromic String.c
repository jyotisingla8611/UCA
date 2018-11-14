#include<stdio.h>
#include<string.h>
char* Palin(char *str){
   int len = strlen(str);
    char *res = (char*)malloc(sizeof(char)*len);
    int m=0;
    int max=0,start=0,end=1,i,j,k;
    int l;
    if(len==1)
     return str;
    for(i=0;i<len-1;i++){
        for(j=i+1;j<len;j++){
                int count=0;
                l=j;
            for(k=i;k<=l;k++,l--){
                if(str[k]==str[l]){
                    count++;
                }
                else
                {
                 count=0;
                 break;
                }
            }
            count=count*2-1;
            if(count>max){
                max=count;
                start = i;
                end = j;
            }
        }
    }
    if(max==0)
    {
        res[0]=str[0];
        res[1]='\0';
        return res;
    }
    if(max==end){
        end=end-1;
    }
    strncpy(res,str+start,end+1);
    res[end+1]='\0';
    return res;
}
int main(){
    char s[100];
    gets(s);
    char *res = Palin(s);
    printf("%s",res);
}
