/*************************************************************************
	> File Name: 25.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年05月02日 星期三 17时43分18秒
 ************************************************************************/

#include<stdio.h>
int fib[3][1005] = {0}; //大数相加
int main() {
    fib[1][0] = fib[1][1] = 1;
    fib[2][0] = fib[2][1] = 1;
    int n = 2;
    while(fib[n % 3][0] < 1000) {
        n++;
        for(int i = 1; i <= fib[(n + 2) % 3][0]; ++i) {
            fib[n % 3][i] = fib[(n + 1) % 3][i] + fib[(n + 2) % 3][i];
        }
        fib[n % 3][0] = fib[(n + 2) % 3][0];
        for(int i = 1; i <= fib[n % 3][0]; ++i) {
            if(fib[n % 3][i] < 10) continue;
            fib[n % 3][i + 1] += fib[n % 3][i] / 10;
            fib[n % 3][i] %= 10;
            fib[n % 3][0] += (i == fib[n % 3][0]);
        }
    }
    printf("%d\n", n);
    return 0;
}
