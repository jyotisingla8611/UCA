#include<stdio.h>
int evenodd(int n)
{
     return ((n&1)? "Odd":"Even");
}
int main()
{
    printf("%s",evenodd(12));
    return 0;
}
