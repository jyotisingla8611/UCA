/*
Sample Input:

4
3 1 2 1
Sample Output:

2 3
Explanation:

1 is occurring two times, whereas 2 and 3 occurs only once.

*/

#include<stdio.h>
#include<stdlib.h>
int comp1( const void *x,const  void *y)
{
    return *((int*)x)-*((int*)y);
}
void check(int *a,int n){
  qsort(a,n,sizeof(int),comp1);
  int i = 0;
  int sum = a[0];
  for(i=1;i<n;i++)
    sum = sum ^ a[i];
 // printf("%d %d %d",sum,sum+1,sum+2);
  for(i=0;i<n;i++){
    if(a[i]^sum)
    {
      printf("%d %d",a[i],a[i]+1);
      break;
    }
  }
}
int main()
{
   int size;
   scanf("%d",&size);
   int a[size];
  int i;
   for(i=0;i<size;i++)
     scanf("%d",&a[i]);
    check(a,size);
    return 0;
}
