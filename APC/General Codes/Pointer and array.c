#include<stdio.h>
int *func(int *x)
{
    static int arr[]={1,2,3,4,5};
    *x=5;
    return arr;
}
int main()
{
    int n,i;
    int *a=func(&n);
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
}
