//To check entered numbers are consecutive or not
#include<stdio.h>
int threeConsecutive(int a, int b, int c)
{
  int arr[3]={a,b,c};
  int i,j,k;
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
  int flag=0;
  for( k=0;k<2;k++)
  {
    int x=arr[k+1]-arr[k];
    if(x==1)
      flag=1;
    else
      flag=0;
  }
  if(flag)
    return 1;
  else
    return 0;
}
int main()
{
    int res=threeConsecutive(10,34,67);
    if(res==1)
        printf("Yes");
    else
        printf("No");
}
