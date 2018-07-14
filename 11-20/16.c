/*************************************************************************
	> File Name: 16.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年05月01日 星期二 21时24分58秒
 ************************************************************************/

#include<stdio.h>
#define BASE 1000    // 采用1000进制减少计算次数
int a[1005] = {0};
int xx(int n) {
    int sum = 0;
    while(n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
} 
int main() {
    a[0] = a[1]= 1;
    for(int i = 0; i < 100; ++i) {   //100次左移操作
        for(int j = 1; j <= a[0]; ++j) a[j] <<= 10; //每次左移10次， 乘1024
        for(int j = 1; j <= a[0]; ++j) {
            if(a[j] < BASE) continue;
            a[j + 1] += a[j] / BASE;
            a[j] %= BASE;
            a[0] += (j == a[0]);
        }
    }
    int res = 0;
    for(int i = 1; i <= a[0]; ++i) {   //每一位求和
        res += xx(a[i]);
    }
    
    printf("%d\n", res);
    return 0;
}
