/**/
/*#include <stdio.h>
int main()
{
  int n,n1;
  scanf("%d",&n);
  n1=binaryToDecimal(n);
  printf("%d",n1);
    return 0;
}
int binaryToDecimal(int n)
{
 int rem,sum=0,ans=1,i;
 int k=0;
  while(n)
  {
    rem=n%10;
    sum=sum+rem*ans;
    n=n/10;
    ans=ans*2;
   k++;
  }
  return sum;
}
#include<stdio.h>
main()
{
    int res = threeConsecutive(3,5,7);
    if(res=1)
        printf("Yes");
    else
        printf("No");
}
int threeConsecutive(int a, int b, int c)
{
  int arr[3]={a,b,c};
  int i,j;
  for( i=0;i<3;i++)
  {
    for( j=0;j<2;j++)
    {
      if(arr[j]>arr[j+1])
      {
        int t;
        t=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=t;
      }
    }
  }
  printf(" %d %d %d \n",arr[0],arr[1],arr[2]);
  int k,flag=0;
  for( k=0;k<2;k++)
  {
    int x=arr[k+1]-arr[k];
    printf("%d ",x);
        if(x == 1)
      flag=1;
    else
      flag=0;
  }
  if(flag==1)
    return 1;
  else
    return 0;
}
#include<stdio.h>

int* add(int a, int b)
{
  int c=a+b;
  return &c;   // C is a local variable
}

int main()
{
  int x=2, y=6;
  int *sum;
  sum = add(x,y);
  printf("x+y = %d\n", *sum);
  return 0;
}*/
/*
#include <stdio.h>
int main()
{
    printf("%d",func1(348));
}
int func1(int a)
{
    int m,n;
    if (a < 10)
        return((10 * a) + a);
    else
	{
	    m = func1(a / 10);
	    n = func1(a % 10);
        return ((100 *  m) + n);
    }
}*/

/*int func1(int a)
{
    if (a <= 1)
            printf("%d=", a);
    else
    {
            func1(a/2);
            printf("%d=", a);
    }
}

#include<stdio.h>
#include<conio.h>

void main()
 {
   int n,m;
   clrscr();
   printf("\t Enter the to check whether it is power of 2: ");
   scanf("%d",&n);
   m=(n&(n-1));
   if(m==0)
       printf("\n\t %d is power of 2",n);
   else
       printf("\n\t %d not power of 2",n);
   getch();
 }
 */
 /*int func1(int a)
{
    if (a < 0)
        return( -func1(-a));
    else
    if(a < 10)
        return (a+1) % 10;
    else
	{
        return (100 * func1(a / 10));
    }
}
int sumOfDigits(int n)
{
  if(n<0)
    return sumOfDigits(-n)*(-1);
  else if(n==0)
    return 0;
  else
    return(n%10 + sumOfDigits(n/10));
}
int main()
{
    printf("%d",sumOfDigits(-29));
}
*/
/*
#include <stdio.h>
int main()
{
   int no,b;
   scanf("%d",&no);
   printf("%d",decimalToBinary(no));
   return 0;
}*/
/*int evenDigits(int n)
{
  if (n < 0) {
        return -evenDigits(-n);
    } else if (n == 0) {
        return 0;
    } else if (n % 2 != 0) {
        return evenDigits(n / 10);
    } else {
    return evenDigits(n/10) * 10 + (n%10);
    }
}

int func1(int a)
{
    if (a >= 20)
        printf("%d=", a);
    else
	{
	    func1(a * 4);
        printf("%d=", a);
	}
}
int decimalToBinary(int n)
{/
   if(n==0)
     return 0;
  else
    return 10 * decimalToBinary(n/2)+(n%2);
}
*/
  #include <stdio.h>
    void f(char *k)
    {
        k++;
        k[2] = 'm';
    }
    void main()
    {
        char s[] = "hello";
        f(s);
        printf("%c\n", *s);
    }
