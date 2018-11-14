#include<stdio.h>
int resetbit(int n,int i)
{
     return (n&(~(1<<(i-1))));
}
int main()
{
    printf("%d",resetbit(9,1));
}
