/*A=[1, 3, 5]

We return

f(1, 1) + f(1, 3) + f(1, 5) +
f(3, 1) + f(3, 3) + f(3, 5) +
f(5, 1) + f(5, 3) + f(5, 5) =

0 + 1 + 1 +
1 + 0 + 2 +
1 + 2 + 0 = 8*/


#include<stdio.h>
int main(){
    int A[]={81,13,2,7,96};
    int n1=5,i,j,k,x,y,count=0;
    for(j=0;j<n1-1;j++){
        for(k=j+1;k<n1;k++){
           for(i=0;i<31;i++){
             x = (A[j]>>i)&1;
             y = (A[k]>>i)&1;
               if(x!=y){
                count++;
                printf(" %d  %d \n",i,count);}
            }
        }
    }
   // count = 2*count;
 printf(" finla\n%d",count);
}
