/*************************************************************************
	> File Name: 4.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年04月16日 星期一 16时16分15秒
 ************************************************************************/

#include<stdio.h>
int ispamic(int num) {
    int mun = 0, x;
    x = num;
    while(x != 0) {
        mun = mun * 10 + x % 10;
        x = x / 10;
    }
    if(num  == mun) return 1;
    return 0;
}
int main() {
    int max = 0;
    for(int i = 999; i > 99; --i) {
        if(i * i < max) break; //如果最大的小于之前求的，退出
        for(int j = i; j > 99; --j ) {

            if(ispamic(i * j) && (i * j) > max){
                max = i *j;
                break;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
