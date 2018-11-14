/*
Sample Input:

2
3
6
15 18 2 3 6 12
7
7
4 5 8 2 2 2 3
Sample Output

3
-1
*/
#include<stdio.h>
int searchrot(int *a,int size,int target){
    int low=0,high = size-1;
    while(low<=high){
        int mid=low + ((high-low)/2);
        if(a[mid]==target)
            return mid;
        if(a[low]<=a[mid]){
            if(a[low]<=target && target<a[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        else{
            if(a[mid]<target && target<=a[high])
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return -1;
}
int main(){
    int size,key,test;
    scanf("%d",&test);
    while(test--){
        scanf("%d%d",&key,&size);
        int a[size],i;
        for(i=0;i<size;i++)
          scanf("%d",&a[i]);
        int res = searchrot(a,size,key);
        printf("%d\n",res);
    }
}
