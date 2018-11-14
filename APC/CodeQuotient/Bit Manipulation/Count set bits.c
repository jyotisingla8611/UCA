#include<stdio.h>
int setbits(int n) {
    int i = 0;
    int count = 0;
    for(i=0;i<32;i++){
        if(n&1)
            count++;
        n=n>>1;
    }
    return count;
}
int main(){
    int num,test;
    scanf("%d",&test);
    while(test--){
    scanf("%d",&num);
    printf("%d\n",setbits(num));
    }
}
