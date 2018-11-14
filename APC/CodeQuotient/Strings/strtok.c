#include<stdio.h>
#include<string.h>
char *strtok_c(char *s,char ch) {
    int n = strlen(s);
    int i;
    if(s[0]!='\0')
    for(i=0;i<n;i++)
        if(s[i]==ch)
        s[i]='\n';
    return s;
}
int main() {
    char s[100];
    gets(s);
    fflush(stdin);
    char ch ;
    scanf("%c",&ch);
    char *res = strtok_c(s,ch);
    puts(res);
}
