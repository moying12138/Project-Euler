/*************************************************************************
	> File Name: 5.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年04月15日 星期日 19时20分14秒
 ************************************************************************/

#include<stdio.h>
int gcd(int a, int b) {
    return !b? a : gcd(b, a%b);//返回最大公约数
}
int main() {
    long res = 1;
    int n;
    scanf("%d", &n);//1到n的最小公倍数
    for(int i = n / 2; i <= n; ++i) {
        res *= i / gcd(res, i);
    }
    printf("%ld\n", res);
    return 0;
}
