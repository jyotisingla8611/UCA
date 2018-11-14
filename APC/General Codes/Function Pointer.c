#include<stdio.h>
int sum(int a,int b)
{
    return a+b;
}
int sub(int a,int b)
{
    return a-b;
}
int main()
{
    int (*p)(int,int);
    p=sum;
    int x=p(10,20);
    printf("sum is : %d\n",x);
    p=&sum;
    int y=(*p)(20,50);
    printf("sum is : %d \n",y);
    p=&sub;
    int z=(*p)(20,50);
    printf("sum is : %d \n",z);
    typedef int (*q)(int ,int);
    q r;
    r=&sum;
    printf("Sum is %d \n",r(20,80));
}
