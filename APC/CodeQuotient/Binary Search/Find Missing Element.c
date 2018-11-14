/*
Sample Input

1
5 4
1 2 3 4 5
3 4 1 2
Sample Output

5
*/
#include <stdio.h>
/* Include other headers as needed */
void merge(int array[], int start, int mid, int end)
{
  int i = start,j = mid+1;
  int temp[end],k=start;
  while(i<=mid && j<=end){
    if(array[i]<array[j])
        temp[k++]=array[i++];
    else
        temp[k++]=array[j++];
  }
  while(i<=mid)
    temp[k++]=array[i++];
  while(j<=end)
    temp[k++]=array[j++];
  for(i=start;i<=end;i++)
    array[i]=temp[i];
}

void mergeSort(int array[], int start, int end)
{
    int mid=(start+end)/2;
  if(start>=end)
    return;
  else{
    mergeSort(array,start,mid);
    mergeSort(array,mid+1,end);
    merge(array,start,mid,end);
  }
}
int binary_search(int A[], int left, int right, int key)
{
  int m;
  while( left <= right )
  {
    m = left + (right-left)/2;
    if( A[m] == key )
      return m;
    if( A[m] < key )
      left = m + 1;
    else
      right = m - 1;
  }
  return -1;
}
int main()
{
    int test,n,n1,i,ans;
    scanf("%d",&test);
    int sum=0;
    while(test--){
        scanf("%d%d",&n,&n1);
        int a[n],a1[n1];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n1;i++)
            scanf("%d",&a1[i]);
        mergeSort(a,0,n-1);
        mergeSort(a1,0,n1-1);
        for(i=0;i<n;i++)
        {
            ans=binary_search(a1,0,n1,a[i]);
            if(ans == -1)
                printf("%d\n",a[i]);
        }
    }

    return 0;
}
