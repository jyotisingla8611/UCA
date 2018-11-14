#include <stdio.h>
int findRotationCount(int arr[], int n)
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
int main(void)
{
    int arr[] = { 3,4,5,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int count = findRotationCount(arr, n);
    printf("The array is rotated %d times", count);

    return 0;
}
