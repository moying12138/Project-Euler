/*************************************************************************
	> File Name: 21.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年05月07日 星期一 19时41分00秒
 ************************************************************************/

#include<stdio.h>

#define MAX 10000
int prime[MAX + 5] = {0}; //存储线性筛筛出的素数
int dnum[MAX + 5] = {0}; // 存储i的因子和
int xnum[MAX + 5] = {0}; //存储i因子中最小素数的前n项和的 分子，q的n次方 - 1
void init() {
    for(int i = 2 ; i <= MAX; ++i) {
        if(!prime[i]) {                //如果是素数
            prime[++prime[0]] = i;
            dnum[i] =  i + 1;
            xnum[i] =  i * i - 1; 
        }
        for(int j = 1; j <= prime[0]; ++j) {
            if(i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) {    //如果prime[j]是i的因子
                xnum[i * prime[j]] = xnum[i] * prime[j] + prime[j] - 1;
                dnum[i * prime[j]] = dnum[i] * xnum[i * prime[j]] / xnum[i]; 
                break;
            } else {                  
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
                xnum[i * prime[j]] = xnum[prime[j]];
            }
        }
    
    }
}
int main(){
    init();
    for(int i = 2; i <= MAX; ++i) {
        dnum[i] -= i;
    }
    int res = 0;
    for(int i = 2; i <= MAX; ++i) {
        if(dnum[i] == i) continue;
        if(dnum[i] > MAX) continue;
        if(dnum[dnum[i]] == i) 
        res += i;
    }
    printf("%d\n", res);
    return 0;
}
