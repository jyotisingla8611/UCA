
#include<stdio.h>
int main()
{
    int arr[5]={1,2,3,4,5};
    int i;
    printf("Address of whole array is %d \n",&arr);
    printf("Address of next 1D array %d",&arr+1);
    int *x;
   // x=&(arr+1);
    printf("Address of next 1D array %d",x);

}
