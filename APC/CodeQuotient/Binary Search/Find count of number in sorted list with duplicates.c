#include <stdio.h>
int lowerbound(int *arr,int size,int num){
    int left = 0;
    int right = size,mid;
    while(left<right){
        mid=(left+right)/2;
        if(arr[mid]>=num)
            right = mid;
        else
            left = mid+1;
    }
    return left;
}

int upperbound(int *arr,int size,int num){
    int left = 0;
    int right = size,mid;
    while(left<right){
        mid=(left+right)/2;
        if(arr[mid]<=num)
            left = mid+1;
        else
            right = mid;
    }
    return right;
}

int main()
{
  int test,i,n,j,k,count,size;
  scanf("%d",&test);
  while(test--){
    scanf("%d %d",&size,&n);
    int a[size];
    for(i=0;i<size;i++)
      scanf("%d",&a[i]);
   int low,high;
    low = lowerbound(a,size,n);
    high = upperbound(a,size,n);
    count=high-low;
    printf("%d\n",count);
  }
    return 0;
}
