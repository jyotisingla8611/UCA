#include<stdio.h>

int binary_search(int A[], int left, int right, int key)
{
  int m;
  while( left <= right )
  {
    m = left + (right-left)/2;
    if( A[m] == key )     // Element found
      return m;
    if( A[m] < key )         // Search in right part of list
      left = m + 1;
    else            // Search in left part of list
      right = m - 1;
  }
  return -1;
}

int main()
{
  int loc, x, array[]={10,11,12,13,14,25,26,37,48,29};
  x = 26;        // element to be searched in the array
  loc=binary_search(array,0,10,x);
  if(loc != -1)
    printf("Element found at location : %d",loc);
  else
    printf("Element not present in the array.");
  return 0;
}
