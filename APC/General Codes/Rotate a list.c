#include <stdio.h>
/* Include other headers as needed */
int main()
{
  int test,rot,n,arr[50],i,j;
  scanf("%d",&test);
  while(test--)
  {
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
    }
    scanf("%d",&rot);
   while(rot>=n)
    rot=rot-n;
    if(rot<0)
        rot=-rot;
    for(i=rot;i<n;i++)
      printf("%d ",arr[i]);
    for(i=0;i<rot;i++)
      printf("%d ",arr[i]);
    printf("\n");
  }
    return 0;
}
