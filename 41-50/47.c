/*************************************************************************
	> File Name: 47.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年05月09日 星期三 10时59分43秒
 ************************************************************************/

#include<stdio.h>
#define MAX 1000000
int prime[MAX + 5] = {0}; //线性筛筛出的质数
int dnum[MAX + 5] = {0};  //i的不同的质因子个数
//int xnum[MAX + 5] = {0};
void init() {
    for(int i = 2; i <= MAX; ++i) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 1;

        }
        for(int j = 1; j <= prime[0]; ++j) {
            if(i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) {
                dnum[i * prime[j]] = dnum[i];
                break;
            } else {
                dnum[i * prime[j]] = dnum[i] + 1;
            }
        }

    }

}
int main() {
    init();
    for(int i = 2; i <= MAX; ++i) {
        if(dnum[i] != 4) continue;
        if(dnum[i + 1] != 4) continue;
        if(dnum[i + 2] != 4) continue;
        if(dnum[i + 3] != 4) continue;
        printf("%d\n", i);
        break;
    }
    
    
    return 0;
}
