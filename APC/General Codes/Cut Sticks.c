#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int* cutSticks(int lengths_size, int *lengths, int *result_size) {
  int *arr2 = (int*) malloc(lengths_size*sizeof(int));
  int i,min=1,count,k=0;
  while(min>0 && min !=INT_MAX)
  {
    count = 0;
    min = INT_MAX;
    for(i=0;i<lengths_size;i++)
     {
    if((*(lengths+i))!=0 && *(lengths+i)<min)
        min = *(lengths+i);
    }
  for(i=0;i<lengths_size;i++)
     {
    if(*(lengths+i)>=min){
             *(lengths+i) = *(lengths+i)-min;
            count++;
         }
      }
      arr2[k++]=count;
    }
    *result_size= k-1;
    return arr2;
}
int main()
{
    int arr[6]={5,4,4,2,2,8};
    int size,i;
    int *arr1 ;
    arr1 = cutSticks(6,arr,&size);
    for(i=0; i< size; i++) {
printf("%d ",arr1[i]);}
}
