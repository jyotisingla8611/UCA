#include<stdio.h>
#include<stdlib.h>
int main(){
    long long int n,w,l;
    long long int i;
    scanf("%lld%lld%lld",&n,&w,&l);
    long long int *h = (long long int*)malloc(sizeof(long long int)*n);
     long long int *r = (long long int*)malloc(sizeof(long long int)*n);
     for(i=0;i<n;i++){
        scanf("%lld%lld",&h[i],&r[i]);
     }
     long long int left=0,right=w,mid;
     while(left<right){
        long long int sum=0;
        mid=(left+right)/2;
        for(i=0;i<n;i++){
            long long int h1=h[i]+(r[i]*mid);
            if(h1>=l){
                sum=sum+h1;
                if(sum>=w)
                    break;
            }
        }
            if(sum>=w)
            {
                right=mid;
            }
           else
            left=mid+1;
     }
     printf("%lld",left);
}
