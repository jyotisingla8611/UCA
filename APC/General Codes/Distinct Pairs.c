int comp1( void *x, void *y)
{
    return *((int*)x)-*((int*)y);
}
int numberOfPairs(int a_count, int* a, long k) {
  qsort(a,a_count,sizeof(int),comp1);
    int l = 0;
    int r = a_count-1;
    int count=0;
    int prev1 = INT_MIN;
    int prev2 = INT_MAX;
    while(l<r){

        if(a[l]+a[r]==k && prev1!=a[l] && prev2!=a[r]){
            count++;
            prev1 = a[l];
            prev2 = a[r];
            l = l+1;
            r = r-1;
        }
        else if(a[l]+a[r]<k){
            l=l+1;
        }
        else
            r=r-1;
    }
    return count;
}
