#include<stdio.h>
void lowerbound(int *arr,int size,int num){
    int left = 0;
    int right = size,mid;
    while(left<right){
        mid=(left+right)/2;
        if(arr[mid]>=num)
            right = mid;
        else
            left = mid+1;
    }
    printf("Lower bound is %d \n",left);
}

void upperbound(int *arr,int size,int num){
    int left = 0;
    int right = size,mid;
    while(left<right){
        mid=(left+right)/2;
        if(arr[mid]<=num)
            left = mid+1;
        else
            right = mid;
    }
    printf("Upperer bound is %d \n",right);
}

int main(){
    int n,i,num;
    scanf("%d",&n);
    int arr[n];
  for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int test;
    printf("Enter number of test cases : ");
    scanf("%d",&test);
    while(test--){
       scanf("%d",&num);
       lowerbound(arr,n,num);
       upperbound(arr,n,num);
    }
}
