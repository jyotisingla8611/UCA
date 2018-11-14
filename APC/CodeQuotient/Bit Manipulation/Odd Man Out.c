/*
Sample Input 1:

7
3 2 1 2 3 1 1
Sample Output 1:

1
Explanation:

1 is present three times whereas rest elements 2 and 3 are present twice.
*/

#include <stdio.h>
/* Include other headers as needed */
int check(int x,int *a,int n){
  int count=0;
  int i;
  for(i=0;i<n;i++){
    if(a[i]==x)
      count++;
  }
  if(count%2 != 0)
    return x;
  return -1;
}
int main()
{
   int size;
   scanf("%d",&size);
   int a[size];
  int i;
   for(i=0;i<size;i++)
     scanf("%d",&a[i]);
  for(i=0;i<size;i++){
    int res = check(a[i],a,size);
    if(res != -1)
    {
      printf("%d\n",res);
      break;
    }
  }
    return 0;
}
