#include<stdio.h>
int bang(int x)
{
    return ((x | (~x +1)) >> 31) + 1;

//    return((((x>>31)|(!(!x)))&1)^1);
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",bang(n));
   // printf("%d",(1&(-1)));
}
