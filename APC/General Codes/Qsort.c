#include<stdio.h>
#include<stdlib.h>
int comp1( void *x, void *y)
{
    return *((int*)x)-*((int*)y);
}
int comp2( int *x, int *y)
{
    return *((int*)y)-*((int*)x);
}
char comp3( void *x, void *y)
{
    return *((char*)x)-*((char*)y);
}
int main()
{
    int arr[6]={7,31,24,3,4,8};
    char arr1[2][100] = {"bgeqasdf" , "acs"};
    int i;
    qsort(arr,6,sizeof(int),comp1);
    printf("Ascending\n");
    for(i=0;i<6;i++)
        printf("%d ",arr[i]);
    qsort(arr,6,sizeof(int),comp2);
    printf("\nDescending\n");
    for(i=0;i<6;i++)
        printf("%d ",arr[i]);
    qsort(arr1,2,sizeof(char*),comp3);
    printf("\nchar\n");
    for(i=0;i<strlen(arr1);i++)
        printf("%c  ",arr1[i]);
}

