#include<stdio.h>
int main()
{
    int n;
    void *x;
    void *y;
    x=&n;
    printf("x i : %d \n",*((int*)x));
    float a;
    x=&a;
    printf("x i : %f \n",*((float*)x));
    int p;
    x=&p;
    printf("x i : %d \n",*((int*)x));
    void *z;
    y=&z;
    printf("y is : %d \n",*((float *)y));
}
