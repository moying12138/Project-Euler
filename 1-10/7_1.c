/*************************************************************************
	> File Name: 7.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年05月01日 星期二 13时45分11秒
 ************************************************************************/

#include<stdio.h>
#define MAX 150000
int prime[MAX + 5] = {0};
int main() {
    for(int i = 2; i < MAX; ++i) {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; ++j) {
            if(i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    printf("%d\n", prime[10001]);
    
    return 0;
}
