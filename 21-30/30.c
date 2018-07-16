/*************************************************************************
	> File Name: 30.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年04月18日 星期三 18时51分52秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int is_fifth(int n) {
    int x = n;
    int sum = 0;
    while(x) {
        int i = x % 10;
        sum += (int)pow(i, 5);
        x /= 10;
    }
    return n == sum;
}
int main() {
    long sum = 0;
    for(int i = 10; i < 1000000; ++i) {
        if(is_fifth(i)) {
            sum += i;
        }
    }
    printf("%ld\n", sum);
}
