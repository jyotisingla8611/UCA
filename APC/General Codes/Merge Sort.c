#include<stdio.h>

void print_array(int array[],int start,int end)
{
  int i;
  for (i=start; i <= end; i++)
    printf("%d\t", array[i]);
  printf("\n");
}

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


int main()
{
  int array[] = {24, 17, 13, 22, 19, 21, 16, 12};
  int array_size = sizeof(array)/sizeof(array[0]);
  int i;

  printf("Given array is :\n");
  print_array(array,0,array_size-1);
  mergeSort(array, 0, array_size - 1);

  printf("\nSorted array is :\n");
  print_array(array,0,array_size-1);
  return 0;
}

