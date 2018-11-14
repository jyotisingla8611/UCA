#include <stdio.h>
/* Include other headers as needed */
int main()
{
  int test;
    int n,w,i,j,k=1,sum=0,fn=0,rows,fn1;
    char ch;
  scanf("%d",&test);
  while(test){
        k=1;
        sum=0;
    scanf("%d%d",&n,&w);
    scanf("%d",&fn);
    fn1=fn;
    rows = ((n/w)+(n%w));
    int a[rows][w];
    for(i=0;i<rows;i++){
      for(j=0;j<w;j++){
        if(k<=n){
          a[i][j]=k;
          k++;
        }
        else
          {
             a[i][j]=0;
          }
      }
    }
    scanf("%s",&ch);
    if(ch == 'r' || ch == 'R')
    {
        for(j=0;j<w;j++)
            sum=sum+a[fn1-1][j];
    }
    else
    {
        for(i=0;i<rows;i++)
            sum=sum+a[i][fn1-1];
    }
    printf("%d\n",sum);
    test--;
  }
    return 0;
}
