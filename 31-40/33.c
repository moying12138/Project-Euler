/*************************************************************************
	> File Name: 33.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年04月25日 星期三 11时22分30秒
 ************************************************************************/

#include<stdio.h>
int gcd(int a, int b) { //返回a和b的最大公约数
    return !b ? a : gcd(b, a % b);
}
int judge(int x, int y) {   //暴力
    int x1, x2, y1, y2;
    x1 = x % 10;//个
    x2 = x / 10;//十

    y1 = y % 10;//个
    y2 = y / 10;//十
    if(!x1 || !x2 || !y1 || !y2) return 0;
    if(x1 == y1 && x2 * y == y2 * x) return 1;
    if(x1 == y2 && x2 * y == y1 * x) return 1;
    if(x2 == y1 && x1 * y == y2 * x) return 1;
    if(x2 == y2 && x1 * y == y1 * x) return 1;
    return 0;

}
int  main() {
    int mix = 1;
    for(int i = 11; i < 100; ++i) {
        for(int j = i + 1; j < 100; ++j) {
            if(judge(i,j)) {
                int x = j;
                x /= gcd(i, j);
                mix *= x;
            }

        }
    }
    printf("%d\n", mix);
    return 0;
}
