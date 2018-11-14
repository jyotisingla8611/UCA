#include<stdio.h>
#include<limits.h>
int main(){
  int test;
  scanf("%d",&test);
  int res,a,b,max = INT_MIN;
  int i;
  while(test--){
  scanf("%d %d",&a,&b);
  for( i=1;i<=b;i++){
    res = a%i;
    if(max<res)
      max = res;
  }
  printf("%d\n",max);
}
}
