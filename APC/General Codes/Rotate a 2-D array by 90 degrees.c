#include<stdio.h>
void rotate(int n , int A[n][n]) {
    int i,j;
    for(i=0;i<n/2;i++)
    {
        for(j=i;j<n-i-1;j++)
        {
            int temp=A[i][j];
            A[i][j]=A[n-1-j][i];
            A[n-1-j][i]=A[n-1-i][n-1-j];
            A[n-1-i][n-1-j]=A[j][n-1-i];
            A[j][n-1-i]=temp;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j==0)
                printf("%d",A[i][j]);
            else
                printf(" %d",A[i][j]);
        }
        printf("\n");
     }
     printf("\n");
    }

int main(){
    int n,test,i,j;
    scanf("%d",&test);
    while(test--){
     scanf("%d",&n);
     int a[n][n];
     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
     }
     rotate(n,a);
}
}
