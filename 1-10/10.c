/*************************************************************************
	> File Name: 10.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年05月01日 星期二 20时00分01秒
 ************************************************************************/

#include<stdio.h>
#define MAX 2000000
int prime[MAX + 5] = {0};
int main() {
    long sum = 0;
    for(int i = 2; i < MAX; ++i) {
        if(!prime[i]) prime[++prime[0]] = i, sum += i;//直接求和
        for(int j = 1; j <= prime[0]; ++j) {
            if(i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    } 
    printf("%ld\n", sum);
    
    return 0;
}
