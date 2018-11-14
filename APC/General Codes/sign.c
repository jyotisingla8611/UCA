#include<stdio.h>
int sign(int x)
{
    return((x>>31)|(!(!x)));
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",sign(n));
}
