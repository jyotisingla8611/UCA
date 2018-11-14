#include<stdio.h>
void moveElements(int arr[], int n)
{
  int j,i,temp;
  for(i=0;i<n;i++)
  {
      for(j=0;j<n-1;j++)
      {
          if(arr[j]<0 && arr[j+1]>=0)
          {
             temp=arr[j];
              arr[j]=arr[j+1];
             arr[j+1]=temp;
          }
      }
  }
}
int main()
{
    int arr[10]={-6,7,13,10,-8,15,5,-9,2,-1};
    moveElements(&arr,10);
    int i;
    for(i=0;i<10;i++)
    printf("%d ",arr[i]);
}
