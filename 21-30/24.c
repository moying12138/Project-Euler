/*************************************************************************
	> File Name: 24.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年05月08日 星期二 14时39分18秒
 ************************************************************************/

#include<stdio.h>
int mix[10] = {0};
int get_num[10] = {0};
int get_num_x(int n, int xx) {
    int x = n / xx + 1;
    int len = 0;
    for(int i = 0; i < 10; ++i) {
        len += !get_num[i];
        if(len == x)  {
            get_num[i] = 1;
            return i;
        }
    }
        return -1; 
}
void init() {
    mix[0] = 1;
    for(int i = 1; i < 10; ++i) {
        mix[i] = i * mix[i - 1];
    }
    return ;
}
int main() {
    init();
    int n, k;
    int num[10] = {0};
    scanf("%d%d", &n, &k); //n为第几个排列 k为有0到k - 1个数 示例为1000000 10
    int xx = mix[k - 1];
    n--;
    for(int i = 0; i < k; ++i) {
        int x = get_num_x(n, xx);
        num[i] = x;
        n = n % xx;
        if(i == k - 1) break;
        xx /= k - i - 1;
    }
    for(int i = 0; i < k; ++i) {
        printf("%d", num[i]);
    }
    printf("\n");
    return 0;
}
