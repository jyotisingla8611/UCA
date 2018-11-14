#include<stdio.h>
#include<math.h>
int main(){
int i,j=0,pos,count=1,sum=0;
scanf("%d",&pos);
while(pos){
    if(pos&1)
        sum=sum+pow(5,count);
    count++;
    pos=pos>>1;
}
printf("sum is %d",sum);
return 0;
}


