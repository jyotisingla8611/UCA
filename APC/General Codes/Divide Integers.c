#include<stdio.h>
int main(){
    int x,y,z,i,j,res1;
    scanf("%d%d",&x,&y);
    for(j=31;j>=0;j--){
        z = y<<j;
        if(z<=x){
          for(i=0;i<31;i++){
            res1 = z + (y<<i);
            if(res1<=x){

            }
          }
        }
    }
}
