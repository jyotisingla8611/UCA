#include <stdio.h>
/* Include other headers as needed */
int main()
{
  int test,i,j,arr[50],n,max=0,k;
  scanf("%d",&test);
  while(test--)
  {
    int count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
        if(arr[i]==arr[j])
        count++;
      }
      if(count>max)
       {
         max=count;
         k=i;
       }
    }
    printf("%d\n",arr[k]);
  }
    return 0;
}
