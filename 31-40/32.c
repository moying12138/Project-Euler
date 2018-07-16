/*************************************************************************
	> File Name: 32_test.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年04月28日 星期六 09时22分36秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define f(a) ((int)(log10(a))) //a的位数 - 1 示例100 返回2

int is_allnum(int a, int *num) {  //互斥原理
    while(a) {
        if(num[a % 10] || a % 10 == 0) return 0;  
        num[a % 10] = 1;
        a /= 10;     
    }
    return 1;
}
int is_all(int a, int b) {
    int num[10] = {0};
    return is_allnum(a,num) && is_allnum(b, num) && is_allnum(a*b, num);
}
int main() {
    int  mix[10000] = {0};
    int ans = 0;
    for(int i = 2; i < 100; ++i) {
        for(int j = 100; ; ++j) {
            int x = f(i) + f(j) + f(i * j) + 3; //判断位数
            if(x < 9) continue;
            if(x > 9) break;
            if(is_all(i, j) && !mix[i * j]) {
                printf("%d\n", i * j);
                mix[i * j] = 1;
                ans += i * j;          
            }           
        }      
    }
    printf("%d\n", ans);
    return 0;

}

