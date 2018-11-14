#include<stdio.h>
int main()
{
    int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int arr[9],k=0,i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;++j)
        {
            arr[k++]=a[i][j];
            if(j==2)
            {
                while(i<2){
                    ++i;
                    arr[k++]=a[i][j];
                   // printf("%d is arr[0]",arr[0]);
                    }
            }
        }
       // printf("%d is j \n",j);
        j=j-1;
        if(i==j)
        {
            while(j!=0){
            --j;
            arr[k++]=a[i][j];
            }
        }

        if(i==2)
            {
                while(i>0){
                    --i;
                    j=0;
                    printf("%d is k \n",k);
                    arr[k++]=a[i][j];}
            }

    }
    for(i=0;i<9;i++)
    {
        printf("%d ",arr[i]);
    }
}
