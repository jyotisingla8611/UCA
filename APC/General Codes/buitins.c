#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    printf("Number of high bits %d" , __builtin_popcount(num));
        printf("\nNumber of leading zeros %d" , __builtin_clz(num));
            printf("\nNumber of trailing zeros %d" , __builtin_ctz(num));
                printf("\nNumber of parity bits %d" , __builtin_parity(num));
}
