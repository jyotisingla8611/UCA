#include<stdio.h>
int *func(int *x)
{
    //If static is not inserted here program will print garbage values .
    static int arr[]={1,2,3,4,5};
    *x=5;
    return &arr;
}
int main()
{
    int n,i;
    //scanf("%d",&n);
    int *a=func(&n);
    printf("Updated n is as %d \n",n);
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
}
