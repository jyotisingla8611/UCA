
#include<stdio.h>
int main()
{
  int a[5],i,max,smax;
  for(i=0;i<5;i++)
    scanf("%d",&a[i]);
  max=smax=a[0];
 for(i=1;i<5;i++)
 {
   if(a[i]>max)
   {
     smax=max;
     max=a[i];
   }
 /*  else if(max==smax)
   {
       smax=a[i];
   }
   if(a[i]>smax && a[i]!=max)
   {
       smax=a[i];
   }
 */}
  printf(" %d",smax);
  return 0;
}
