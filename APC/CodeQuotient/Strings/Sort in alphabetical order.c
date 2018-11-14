#include <stdio.h>
void sort_alpha(char array1[])
{
    int num1[26] = {0}, i = 0,j=0;
    char res[26];
    while (array1[i] != '\0')
    {
        num1[array1[i] - 'a']++;
        i++;
    }
    for(i=0;i<26;i++){
        if(num1[i]>1)
        {
            while(num1[i]){
                res[j++]=i+'a';
                num1[i]--;
            }
        }
        if(num1[i]!=0){
            res[j++]= i+'a';
        }
    }
    res[j]='\0';
    //printf("%s \n",res);
    printf("Sorted string is as : \n");
    for(i=0;i<j;i++)
        printf("%c",res[i]);
}
int main()
{
    char array1[100];
    printf("Enter the string\n");
    gets(array1);
    sort_alpha(array1);
    return 0;
}

