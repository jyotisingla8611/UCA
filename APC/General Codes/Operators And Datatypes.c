#include<stdio.h>
int main()
{
    int c;
    c=func1()+func2();
    printf("On adding 2 functions : %d \n",c);
    int a=2,b=3,d=4,h=0;
    int e;
    e=a,b;
    int f=(a,b,d);
    printf("Value of e to check precedence of , : %d\n",e);
    printf("Value of f to check associativity of () : %d\n",f);
    int g,k;
    g= a||++b;
    printf("Logical or if a is true : %d\nValue of b is :%d\n",g,b);
    k= h||++b;
    printf("Logical or if h is false : %d\nValue of b is :%d\n",k,b);
}
int func1()
{
    printf("Hello Func1\n");
    return 10;
}
int func2()
{
    printf("Hello Func2\n");
    return 20;
}
