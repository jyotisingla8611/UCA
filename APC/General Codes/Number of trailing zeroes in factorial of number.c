#include<stdio.h>
long long int fact(int n)
{
    long long ans = 1;
    int i;
    for(i=1; i <= n; i++)
    ans *= i;
return ans;
}
int trail(int x){
    long long  int n =fact(x);
    printf("fact is %lld",n);
    int count=0;
while(n){
   long long int rem;
   rem = n%10;
   if(rem==0)
     count++;
   else
      break;
    n=n/10;
}
return count;
}
int main()
{
    int a;
    scanf("%d",&a);
    int res = trail(a);
    printf("%d",res);
}
