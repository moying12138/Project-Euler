/*************************************************************************
	> File Name: 14.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年05月01日 星期二 21时04分00秒
 ************************************************************************/

#include<stdio.h>
#define MAX 30000000
int a[MAX + 5] = {0};  //记忆化数组
int most_length(long n) {
    if(n == 1) return 1;
    if(n < MAX && a[n]) return a[n]; 
    int res;
    if(n % 2 == 0) {
        res = most_length(n / 2) + 1;
    } else {
         res = most_length(3 * n + 1) + 1;
    }
    if(n < MAX) a[n] = res;
    return res;
}

int main() {
    int res = 0, ans = 0;

    for(int i = 1; i < 1000000; ++i) {
        int x = most_length(i);
        if(x > res) {
            res = x;
            ans = i;
        }
    }    
   printf("%d\n", ans); 
    return 0;
}
