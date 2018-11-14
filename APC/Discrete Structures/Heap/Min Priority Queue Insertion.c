//MINIMUM PRIORITY QUEUE i.e PARENT WILL BE MINIMUM

#include<stdio.h>
#include<stdlib.h>
void insert_min(int *arr,int num,int *index){
    if(*index == 1) {
        arr[*index] = num;
        (*index)++;
        return;
    }
    arr[*index] = num;
    int in = *index;
    while(arr[(in)/2] > arr[in] && in>1) {
        int temp = arr[(in)/2];
        arr[(in)/2] = arr[in];
        arr[in] = temp;
        in = in/2;
    }
    (*index)++;
}
int main() {
    int size;
    int i = 0;
    scanf("%d",&size);
    int *arr = (int*)malloc(sizeof(int)*size);
    int *index = 1;
    for(i=0;i<size;i++){
        int num;
        scanf("%d",&num);
        insert_min(arr,num,&index);
    }
    for(i=1;i<=size;i++)
        printf("%d ",arr[i]);
}
