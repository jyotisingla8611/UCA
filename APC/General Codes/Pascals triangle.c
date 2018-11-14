#include<stdio.h>
int fact(int a)
{
    if(a==1 || a==0)
        return 1;
    else
        return(a*fact(a-1));
}
int main()
{
    int n=5,i,j,out;
    int N=5,r,n1,n2;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
           n1=fact(i);
           n2=fact(j);
           r=fact(i-j);
           out=(n1/(n2*r));
           printf("%d ",out);
        }
        printf("\n");

    }
}



/**
 * @input A : Integer
 *
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row, len2 as columns
 */
 int fact(int a)
{
    if(a==1 || a==0)
        return 1;
    else
        return(a*fact(a-1));
}
int ** solve(int A, int *len1, int *len2) {
    int n1,n2,r,out,i,j;
    *len1=*len2=A;
    int **B=NULL;
    B=(int **)malloc(sizeof(int*)*(*len1));
    for(i=0;i<(*len1);i++)
     B[i]=(int *)malloc(sizeof(int)*(i));
     for(i=0;i<A;i++)
     {
         for(j=0;j<=i;j++)
         {
            n1=fact(i);
           n2=fact(j);
           r=fact(i-j);
           out=(n1/(n2*r));
           B[i][j]=out;
         }
     }
     return B;
}
