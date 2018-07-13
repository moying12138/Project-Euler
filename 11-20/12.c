/*************************************************************************
	> File Name: 12.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年05月01日 星期二 20时19分33秒
 ************************************************************************/

#include<stdio.h>
#define MAX 1000000
int prime[MAX +5] = {0};
int nnum[MAX + 5] = {0}; //记录i的因子个数
int xnum[MAX + 5] = {0}; //记录i中的最小质因子的幂次
void init() {
    for(int i = 2; i < MAX; ++i) {
        if(!prime[i]) prime[++prime[0]] = i, nnum[i] = 2, xnum[i] = 1; 
        for(int j = 1; j <= prime[0]; ++j) {
            if(i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) {
                nnum[i * prime[j]] = nnum[i] / (xnum[i] + 1) * (xnum[i] + 2);
                xnum[i * prime[j]] = xnum[i] + 1;
                break;
            } else {
                xnum[i * prime[j]] = 1;
                nnum[i * prime[j]] = nnum[i] * nnum[prime[j]];
            }
        }
    }
}
int main() {
    init();
    int ans = 0, n = 2;
    nnum[1] = nnum[0] = 1;
    while(ans <= 500) {
        if(n % 2 == 1) {
          ans = nnum[n] * nnum[(n + 1) / 2];  
        } else {
            ans = nnum[n / 2] * nnum[n + 1];
        }
        n++;
    }
    printf("%d\n", n * (n - 1) / 2);
    
    return 0;
}
