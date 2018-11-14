#include<stdio.h>
int main()
{
  float x= 5.3f;
  unsigned char *ch=(char*)(&x);
  signed char *ch1=(char*)(&x);

  int i;
  for(i=0;i<4;i++)
  {
      printf("%d ",*(ch+i));
  }
  printf("\n");
  for(i=0;i<4;i++)
  {

      /*int b;
      b=*(ch1+i);
      if(b<0)
        b+=256;
    printf("%d ",b);*/
    printf("%d ",*(ch1+i));
  }
}
