/*
    a + k = b
    and b will should be in array

    */
// Complete the countPairs function below.
int comp1( void *x, void *y)
{
    return *((int*)x)-*((int*)y);
}
int binary_search(int A[], int left, int right, int key)
{
  int m;
  while( left <= right )
  {
    m = left + (right-left)/2;
    if( A[m] == key )
      return m;
    if( A[m] < key )
      left = m + 1;
    else
      right = m - 1;
  }
  return -1;
}

int countPairs(int a_count, int* a, int k) {
  qsort(a,a_count,sizeof(int),comp1);
    int l = 0;
    int r = a_count;
    int count=0;
    while(l<r){
        if(a[l]==a[l+1])
            l=l+1;
        else
        {
          int x = a[l]+k;
          int res = binary_search(a,l,r,x);
          if(res != -1)
            count++;
            l=l+1;
        }
    }
    return count;

}

