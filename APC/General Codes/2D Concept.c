#include<stdio.h>
int i,j;
//void func1(int (*a)[][],int r,int c)  Not Applicable as size is not specified
void func1(int r,int c,int (*a)[r][c])
{
    //As here we are recieving address of whole arrray
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",*(*(*a+i)+j));
        }
        printf("\n");
    }
}
void func2(int r,int c,int a[r][c]) // Or int (*a)[r]
{
    //As here we are recieving address of 1st 1D array
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void func3(int *a,int r,int c)
{
    //As here we r recieving address of 1st element
    for(i=1;i<=r*c;i++)
    {
     printf("%d ",*(a+i-1));
     if(i%3==0)
        printf("\n");
    }
}
int main()
{
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    printf("On calling Function1\n");
    func1(3,3,&arr);
    printf("On calling Function2\n");
    func2(3,3,arr);
    printf("On calling Function3\n");
    func3(*arr,3,3);
}

