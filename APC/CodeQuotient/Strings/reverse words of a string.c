#include<stdio.h>
void swap(char *a,char *b){
char c;
c=*a;
*a=*b;
*b=c;
}
void revWordsString(char *str)
{
    int i=0,k,l=0,m,j;
    for(i=0;i<str[i]!='\0';i++){

        if(str[i]==' '){
            k=i;
           // printf("%d %d \n",l,k);
            m=k+1;
            str[k]=' ';
            for(j=l;j<=(--k);j++){
                swap(&str[j],&str[k]);
            }
            l=m;
        }
        if(str[i+1]=='\0'){
            k=i+1;
           // printf("%d %d \n",l,k);
            m=k+1;
            for(j=l;j<=(--k);j++,k){
                swap(&str[j],&str[k]);
            }
            l=m;
        }
    }
}

int main()
{
    char arr[100]="Code Quotient Loves Code";
     revWordsString(&arr);
     printf("%s\n",arr);
     revWordsString(&arr);
     printf("%s",arr);
}
