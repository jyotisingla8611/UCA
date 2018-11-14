/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 *
 * @Output Integer
 */
int maxArr(int* A, int n1) {
    int  min1=A[0]-1,max1=A[0]-1,min2=A[0]+1,max2=A[0]+1;
    int i;
    for(i=1;i<n1;i++)
    {
        if((A[i]-(i+1)<min1))
        min1=A[i]-(i+1);
        if((A[i]+i+1)<min2)
        min2=A[i]+i+1;
        if((A[i]-(i+1))>max1)
        max1=A[i]-(i+1);
        if((A[i]+i+1)>max2)
        max2=A[i]+i+1;
    }
    if((max1-min1)>max2-min2)
    return(max1-min1);
    return(max2-min2);
}
