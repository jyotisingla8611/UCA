#include <stdio.h>
/* Include other headers as needed */
int main()
{
  int test,temp,i,j,k,n;
  scanf("%d",&test);
  while(test--)
  {
    int c=0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
      scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
      k=i;
      for(j=i+1;j<n;j++){
        if(a[j]<a[k]){
          k=j;
        }
      }
      if(i!=k)
        c++;
       temp=a[i];
      a[i]=a[k];
      a[k]=temp;

    }
    printf("%d\n",c);
  }
    return 0;
}
