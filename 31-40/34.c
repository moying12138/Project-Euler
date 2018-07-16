/*************************************************************************
	> File Name: 34.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年04月18日 星期三 19时13分00秒
 ************************************************************************/

#include<stdio.h
#define MAX_N 2540160 // 9! * 7
int fac(int n) {
    int  sum = 1;
    for(int i = 2; i <= n; ++i) {
        sum *= i;
    }
    return sum;
}
int is_fac(int n) {
    int  x = n;
    int sum = 0;
    while(x) {
        sum += fac(x % 10);
        x /= 10;
    }
    return n == sum;
}
int main() {
    int sum = 0;
    for(int i = 3; i < MAX_N; ++i) {
        if(is_fac(i)) {
            printf("%d\n", i);
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
