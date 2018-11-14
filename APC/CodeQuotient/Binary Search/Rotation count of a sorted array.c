/*
Sample Input
2
6
15 18 3 4 6 12
6
1 2 3 4 5 6
Sample Output
2
-1
*/
#include<stdio.h>
int rotationCount(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        if(arr[0]<=arr[high])
          return -1;
        if (arr[low] <= arr[high])
            return low;
        int mid = (low + high) / 2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;
        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
            return mid;
        else if (arr[mid] <= arr[high])
            high = mid - 1;
        else if (arr[mid] >= arr[low])
            low = mid + 1;
    }
    return -1;
}
int main(){
 int test,size,i=0,res;
 scanf("%d",&test);
 while(test--){
    scanf("%d",&size);
    int a[size];
    for(i=0;i<size;i++)
       scanf("%d",&a[i]);
    res = rotationCount(a,size);
    printf("%d\n",res);
 }
 }
