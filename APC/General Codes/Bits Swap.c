#include<stdio.h>
int main(){
    int n;
    printf("Enter a number \n");
    scanf("%d",&n);
    int res ;
    int x = n<<1 & 0xAAAAAAAA;
    printf("x is %d \n",x);
    int y = n>>1 & 0x55555555;
    printf("y is %d \n ",y);
    printf("%d",x|y);
   // res = (n>>1 & 0x55555555 )| (n<<1 & 0xAAAAAAAA);
    //printf("%d",res);
}


//(0x55555555)16 = (0000 0000 0101 0101 0101 0101 0101 0101 0101 0101)2

//(0xAAAAAAAA)16 = (0000 0000 1010 1010 1010 1010 1010 1010 1010 1010)2
