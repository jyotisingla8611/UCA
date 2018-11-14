#include<stdio.h>
int main()
{
  unsigned int x=0xffff;
      printf("%d \n",x<<4);
  int c= ~x;
      printf("%d %d \n",x,c);
      int p=-1,q=4;
      printf("Left shift : %d\n",p<<q); // -16
      printf("Right Shift : %d\n",p>>q); // -1
}
