/*************************************************************************
	> File Name: 6.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年04月15日 星期日 20时01分40秒
 ************************************************************************/

#include<stdio.h>
int main() {
    long sum = 0, sum2 = 0;
    for(int i = 1; i < 101; ++i) {
        sum += i * i;
        sum2 += i;
    }
    printf("%ld\n", sum2 * sum2 - sum);
    return 0;
}
