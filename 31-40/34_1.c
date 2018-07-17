/*************************************************************************
	> File Name: 34_1.c
	> Author: moying
    > Mail: 
	> Created Time: 2018年04月28日 星期六 09时32分33秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 2540160 // 9! * 7
int num[10] = {0};
int init_num(int n) {
    if(n == 1 || n == 0) return 1;
    if(!num[n]) num[n] = n * init_num(n - 1);
    return num[n];

}
int is_fac(int n) {
    int  x = n;
    int sum = 0;
    while(x) {
        sum += num[x % 10];
        x /= 10;
            
    }
    return n == sum;

}
int main() {
    int sum = 0;
    num[0] = num[1] = 1;
    init_num(9);
    for(int i = 3; i < MAX_N; ++i) {
        if(is_fac(i)) {
            printf("%d\n", i);
            sum += i;   
        }  
    }
    printf("%d\n", sum);
    return 0;

}

