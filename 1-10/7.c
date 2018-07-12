/*************************************************************************
	> File Name: 7.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年04月16日 星期一 16时33分35秒
 ************************************************************************/

#include<stdio.h>
#define MAX 200000
int main() {
    int prime[MAX] = {0};
    for(int i = 2; i * i < MAX; ++i) {
        if(!prime[i]) {
            for(int j = i * i; j < MAX; j += i) {
                prime[j] = 1;
            }
        }
    }
    int count = 0, i;
    for(i = 2; count < 10001; ++i) {
        if(!prime[i]) {
            ++count;
        }
    }
    printf("%d\n", i - 1);
}
