#include <stdio.h>
int main()
{
  int test,i,j=0,k,size,n;
  scanf("%d",&test);
  while(test--){
    scanf("%d %d",&size,&n);
    int arr[size];
    for(i=0;i<size;i++)
      scanf("%d",&arr[i]);
    k=size;
    while(j<k){
      int mid = (j+k)/2;
      if(arr[mid]>=n)
        k=mid;
      else
        j=mid+1;
    }
    printf("%d\n",j);
  }
    return 0;
}
