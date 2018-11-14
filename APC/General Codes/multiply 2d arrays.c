#include<stdio.h>
void main()
{
    int test;
    int r1,r2,r3,c1,c2,c3,i,j,k;
    scanf("%d",&test);
    while(test--){
    scanf("%d%d",&r1,&c1);
    int m1[r1][c1];
   for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
            scanf("%d",&m1[i][j]);
   scanf("%d%d",&r2,&c2);
    int m2[r2][c2];
   for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
            scanf("%d",&m2[i][j]);
    if(c1!=r2)
    {
       printf("not possilbel");
    }
    else
    {
    r3=r1;
    c3=c2;
    int m3[r3][c3];
    for(i=0;i<r3;i++)
    {
        j=0;
        for(j=0;j<c3;j++)
        {
            m3[i][j]=0;
            for(k=0;k<c1;k++)
            {
            m3[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
    for(i=0;i<r3;i++)
    {
        printf("\n");
        for(j=0;j<c3;j++)
            printf("%d ",m3[i][j]);
    }
  }
}
}
