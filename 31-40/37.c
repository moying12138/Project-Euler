/*************************************************************************
	> File Name: 37.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年04月18日 星期三 19时30分02秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX 1000000
#define f(a) ((int)(log10(a)))
int prime[MAX] = {0};
int sum = 0;
int is_trun_right(int n) { //依次删除最低位
    int w = f(n);
    while(w != 0) {
        n %= (int)pow(10, w);
        if(prime[n]) return 0;
        --w;
    }
    if(prime[n]) return 0;
    return 1;
}
int is_trun(int n) {   //删除最高位
    while(n) {
        if(prime[n]) return 0; 
        n /= 10;
    }
    return 1;
}

int main() {
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 2; i * i < MAX; ++i) {
        if(!prime[i]) {
            for(int j = i * i; j < MAX; j += i) {
                prime[j] = 1;
            }
        }
    }
    int count = 0;
    for(int i = 11; i < MAX && count < 12; ++i) {
        if(!prime[i] && is_trun(i) && is_trun_right(i)) {
            sum += i;
            printf("%d  ", i);
            count++;
        }
    }
    printf("%d\n", sum);
    return 0;
}
