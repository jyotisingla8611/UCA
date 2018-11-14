#include <stdio.h>
#include<math.h>
int count(int num) {
    int cnt = 0;
    while(num) {
        num /= 10;
        cnt++;
    }
    return cnt;
}
int addOne(int num) {
    int cnt = count(num);
    while(cnt) {
        num += pow(10, --cnt);
    }
    return num;
}
int main()
{
int t, num;
    printf("Enter number of test cases : ");
    scanf("%d", &t);
    while(t--) {
        printf("\nEnter number : ");
        scanf("%d", &num);
        printf("%d\n", addOne(num));
    }
    return 0;
}
