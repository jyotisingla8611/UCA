#include<stdio.h>
int main(){
    int test,n,i,j,k,p,q;
    scanf("%d",&test);
    while(test--){
        scanf("%d %d",&n,&k);
        int a[n];
        int count=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
            p=0;
            q=n-1;
        while(p<=q){
            if(a[p+1]==a[p+2] && a[p+1]+a[p+2]==k){
                    count++;
                }
            if((a[p]+a[q]) == k)
            {
                printf("p is %d and q is %d  ",p,q);
                printf(" %d %d \n",a[p],a[q]);
                count++;
                p++;
            }
            else if(a[p]+a[q]<k)
                p++;
            else
                q--;
        }
        printf("%d\n",count);
    }
}
