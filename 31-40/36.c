/*************************************************************************
	> File Name: 36.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年04月18日 星期三 19时31分51秒
 ************************************************************************/

#include<stdio.h>

int is_base(int n, int base) {    //base为进制
    int x = n;
    int sum = 0; 
    while(x) {
        sum = sum * base + x % base;    
        x /= base;
    }
    return sum == n; 
}
int main() {
    int sum = 0;
    for(int i = 1; i < 1000000; i += 2) {
        if(is_base(i,10) && is_base(i, 2)) {
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
