#include<stdio.h>
int conditional(int a,int b,int c)
{
    return((!!a)*b + (!a)*c);
}
int main()
{
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    printf("%d",conditional(x,y,z));
}
