#include <stdio.h>

void isAnagram(char [], char []);

int main()
{
    char str1[100], str2[100];
    int test = 1;
   // scanf("%d", &test);
    while(test){
    printf("Enter the string\n");
    gets(str1);
    printf("Enter another string\n");
    gets(str2);
     isAnagram(str1, str2);
     test--;
    }
    return 0;
}

void isAnagram(char *str1, char* str2)
{
    int num1[26] = {0}, num2[26] = {0}, i = 0,flag=0;

    while (str1[i] != '\0')
    {
        num1[str1[i] - 'a']++;
        i++;
    }
    i = 0;
    while (str2[i] != '\0')
    {
        num2[str2[i] -'a']++;
        i++;
    }
    for (i = 0; i < 26; i++)
    {
        if (num1[i] != num2[i])
            {
                flag=1;
                break;
            }
    }
    if(flag==1)
        printf("NO");
    else
        printf("YES");
}
