#include<stdio.h>
int main()
{
    int a[5][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15}};
    int arr[15],k=0,i=0,j=0;
    while(j<3)
    {
        arr[k++]=a[i][j++];
    }
    j=j-1;
    while(++i<5)
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
    if(i==j)
    {
        i=i+1;
        while(++j<3)
            arr[k++]=a[i][j];
    }
    for(i=0;i<15;i++)
    {
        printf("%d ",arr[i]);
    }
}
