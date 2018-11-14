#include<stdio.h>
int main()
{
    int a[2][3][2]={{{2,4},{7,8},{3,4}},{{2,2},{2,3},{3,4}}};
    printf("Address of 1st 2D array : %d \n",a);
    printf("Address of 1st 1D array of 1st 2D array : %d \n",*a);
    printf("Address of 1st element : %d \n",**a);
    printf("Value of 1st element : %d \n",***a);
    printf("Address of 2nd 2D array : %d \n",a+1);
    printf("Address of 2nd 1D array : %d \n",*a+1);
    printf("Address of 2nd element : %d \n",**a+1);
    printf("Value : %d \n",***a+1);
}
