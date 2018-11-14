#include <stdio.h>
/* Include other headers as needed */
int main()
{
  int test;
    int n,w,i,j,k=0,sum=0,fn=0,fn1;
    char ch;
  scanf("%d",&test);
  while(test--){
        k=0;
        sum=0;
    scanf("%d%d",&n,&w);
    scanf("%d",&fn);
    fn1=fn;
    scanf("%c", &ch);
    if(ch == 'r' || ch == 'R')
    {
        k=0;
        for(j=((fn1-1)*w)+1;k<w&&j<=n;j++,k++)
            sum=sum+j;
    }
    else
    {
        for(i=fn1;i<=n;i=i+w)
            sum=sum+i;
    }
    printf("%d\n",sum);
  }
    return 0;
}
