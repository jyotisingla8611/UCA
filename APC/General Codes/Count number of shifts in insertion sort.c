#include <stdio.h>
/* Include other headers as needed */
int main()
{
  int i,j,k,n,test,shift=0,swap,key;
  scanf("%d",&test);
  while(test--){
    scanf("%d",&n);
    int a[n];
    shift=0;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++){
      j=i-1;
      key=a[i];
      if(j >= 0 && a[j]>key)
        ++shift;
      while(j >= 0 && a[j]>key){
        a[j+1]=a[j];
        ++shift;
        j--;
      }
      a[j+1]=key;

    }
    printf("%d\n",shift);
  }
    return 0;
}
