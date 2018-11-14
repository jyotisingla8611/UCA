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
