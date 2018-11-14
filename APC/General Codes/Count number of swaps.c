#include <stdio.h>
/* Include other headers as needed */
int main()
{
  int test,n,i,j,temp;
  scanf("%d",&test);
  while(test--)
  {
    int count=0;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    for(i=0;i<n-1;i++)
    {
      for(j=0;j<n-1;j++)
      {
        if(arr[j+1]<arr[j])
        {
          temp=arr[j];
          arr[j]=arr[j+1];
          arr[j+1]=temp;
          count++;
        }
      }
    }
    printf("%d\n",count);
  }
    return 0;
}
