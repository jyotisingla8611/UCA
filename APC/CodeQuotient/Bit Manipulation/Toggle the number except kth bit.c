#include<stdio.h>
int toggle(int n,int k) {
    int i = 0;
    for(i=0;i<32;i++){
        if(i!=k)
            n=n^(1<<i);
        }
    return n;
}
int main(){
    int num,k;
    scanf("%d%d",&num,&k);
    printf("%d",toggle(num,k));
    printf("%d", ~(num ^ (1 << k)));
}

