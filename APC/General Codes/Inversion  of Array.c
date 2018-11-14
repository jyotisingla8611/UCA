#include <stdio.h>
#include<stdlib.h>
int merge(int *a, int l, int m, int r)
{
    int *aux = malloc(sizeof(int)*(r+1));
  int cnt=0;
  int i=l,j=m+1,k;
  for(k=l;k<r;k++){
      if(i>m)
      aux[k]=a[j++];
      else if(j>r)
      aux[k]=a[i++];
      else if(a[i]>a[j]){
          aux[k]=a[j++];
          cnt++;
      }
      else
      aux[k]=a[i++];
  }
  return cnt;
}
int mergesort(int *a,int l,int r){
    if(l==r)
    return 0;
    int mid = (l+r)/2;
     int count = 0;
    count +=  mergesort(a,l,mid);
    count +=  mergesort(a,mid+1,r);
    count += merge(a,l,mid,r);
    return count;
}
int main() {
	int n,i,*a,test;
	scanf("%d",&test);
	while(test--){
	    scanf("%d",&n);
	a=malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
	    scanf("%d",&a[i]);
	}
	int left = 0;
	int right = n-1;
	int res = mergesort(a,left,right);
	printf("%d",res);
	}
	return 0;
}
