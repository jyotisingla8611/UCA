#include<stdio.h>
/*int kthLargest(int arr[], int size, int k)
{
  int i,j,swap;
  for(i=0;i<size;i++)
  {
    for(j=0;j<size-1;j++){
      if(arr[j]<arr[j+1])
      {
        swap=arr[j+1];
        arr[j+1]=arr[j];
        arr[j]=swap;
      }
    }
  }
  for(i=0;i<size;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
  return arr[k];
}*/
int comp1(void *x,void *y){
    return *((int*)y) - *((int*)x);
}
int main()
{
    int arr[]={74, 85, 102, 99, 101, 56, 84};
    qsort(arr,7,sizeof(int),comp1);
    //int res=kthLargest(arr,7,0);
    int i = 0;
    for(i=0;i<7;i++)
        printf("%d  ",arr[i]);
    printf("\n%d",arr[2]);
}
