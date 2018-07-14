/*************************************************************************
	> File Name: 20.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年05月02日 星期三 17时31分13秒
 ************************************************************************/

#include<stdio.h>

#define BASE 10
int a[100] = {0};
int main() {
    a[0] = a[1] = 1;
    for(int i = 2; i < 101; ++i) { //100阶乘的乘积
        for(int j = 1; j <= a[0]; ++j) a[j] *= i;
        for(int j = 1; j <= a[0]; ++j) {
            if(a[j] < BASE) continue;
            a[j + 1] += a[j] / BASE;
            a[j] %= BASE;
            a[0] += (j == a[0]);
        }
    }
    int res = 0;
    for(int i = 1; i <= a[0]; ++i) { //每一位求和
        res += a[i];
    }
    printf("%d", res);

    
    return 0;
}
