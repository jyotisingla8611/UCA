#include<stdio.h>
int main()
{
    int a[3][4]={{1,2,3,0},{4,5,6,1},{7,8,9,2}};
    int arr[12],k=0,i=0,j=0;
    while(j<4)
    {
        arr[k++]=a[i][j++];
    }
    j=j-1;
    while(++i<3)
    {
        arr[k++]=a[i][j];
    }
   // printf("%d %d i j \n",i,j);
     i=i-1;
     while(j!=0)
     {
         arr[k++]=a[i][--j];
     }
   // printf("%d %d i j \n",i,j);
    while(--i>0 && i!=0)
    {
        arr[k++]=a[i][j];
    }
    printf("%d %d i j \n",i,j);
    if(i==j && i==0 && j==0)
    {
        i=i+1;
        while(++j<4)
            arr[k++]=a[i][j];
    }
    for(i=0;i<12;i++)
    {
        printf("%d ",arr[i]);
    }
}
