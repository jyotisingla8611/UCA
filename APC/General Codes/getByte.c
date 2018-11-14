#include<stdio.h>
int getByte(int x,int n)
{
    int res=(x >> (n * 8)) & 0xFF;
    return res;
}
int main()
{
    int res;
    res=getByte(600,1);
    printf("Result is : %d ",res);
}


