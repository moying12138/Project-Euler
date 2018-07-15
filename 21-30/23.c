/*************************************************************************
	> File Name: 23.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年05月07日 星期一 20时12分07秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define MAX 28123
int prime[MAX + 5] = {0}; //同21题
int dnum[MAX + 5] = {0};
int xnum[MAX + 5] = {0};
void init() {
    for(int i = 2; i <= MAX; ++i) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = i + 1;
            xnum[i] = i * i - 1;
        }
        int xx;
        for(int j = 1; j <= prime[0]; ++j) {
            xx = i * prime[j];
            if(xx > MAX) break;
            prime[xx] = 1;
            if(i % prime[j] == 0) {
                xnum[xx] = (xnum[i] + 1) * prime[j] - 1;
                dnum[xx] = dnum[i] * xnum[xx] / xnum[i];
                break; 
            } else {
                dnum[xx] = dnum[i] * dnum[prime[j]];
                xnum[xx] = xnum[prime[j]];
            }
        }
    }
}
void print() {
    for(int i = 0; i <= dnum[0]; ++i) {
        printf("%d ", dnum[i]);
    }
}
int main() {
    init();
    for(int i = 2; i <= MAX; ++i) {
        dnum[i] -= i;
        if(dnum[i] > i) dnum[++dnum[0]]  = i;
    }
    //print();
    memset(prime, 0, sizeof(prime));
    for(int i = 1; i <= dnum[0]; ++i) {
        for(int j = i; j <= dnum[0]; ++j) {
            if(dnum[i] + dnum[j] > MAX) break;
            prime[dnum[i] + dnum[j]] = 1;
        }
    }
    long res = 0; 
    for(int i = 1; i <= MAX; ++i) {
        if(!prime[i]) res += i;
    }
    printf("%ld\n", res);
    return 0;
}
