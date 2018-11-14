// C++ code to add add
// one to a given number
#include <stdio.h>

int addOne(int x)
{
    int m = 1;
    while( x & m )
    {
        x = x ^ m;
        m <<= 1;
    }
   // printf("%d is m \n",m);
    x = x ^ m;
    return x;
}
int main()
{
    printf("%d", addOne(13));
    //getchar();
    return 0;
}
