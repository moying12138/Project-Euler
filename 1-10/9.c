/*************************************************************************
	> File Name: 9.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年05月09日 星期三 08时51分52秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int gcd(int a, int b) {
    return !b ? a : gcd(b , a % b); //返回a和b的最大公约数
}


int main() {
    int a, b, c, flag = 1;
    for(int i = 1; i <= 32 && flag; ++i) {
        for(int j = i + 1; j <= 32; ++j) {
            if(gcd(i, j) != 1) continue;
            a = j * j - i * i;
            b = 2 * i * j;
            c = i * i + j * j;
            if(1000 % (a + b + c) == 0) {
                int x = (int) pow(1000 / (a + b + c) , 3); //三个元素扩大倍数相乘
                printf("%d %d %d %d\n", x * a * b * c, a, b, x);
                flag = 0;
                break;
            }
        }
    }
    
    
    return 0;
}
