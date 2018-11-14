#include<stdio.h>
int * mergeArrays(int a[], int b[], int asize, int bsize)
{
  int i,j,temp;
    for(i=asize,j=0;i<(asize+bsize),j<bsize;i++,j++)
        a[i]=b[j];
    for(i=0;i<(asize+bsize);i++)
    {
      for(j=0;j<((asize+bsize)-1);j++)
      {
        if(a[j]>a[j+1])
        {
          temp=a[j];
          a[j]=a[j+1];
          a[j+1]=temp;
        }
      }
    }
  return a;
}

