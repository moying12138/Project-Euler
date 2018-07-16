/*************************************************************************
	> File Name: 29.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年05月08日 星期二 18时59分58秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define MAX 10000
typedef struct power{ //a为底， n为幂次
    int a, n;
}Power;
Power mix[MAX + 5][4] = {0};//只需要4个每列，因为2 × 3 × 5 × 7 = 210 > 100 所以小于100的底不可能分离出4个质因子相乘
int M_sum = 0;
int prime[MAX + 5] = {0}; //存储i的非1最小因子

void init() {
    for(int i = 2; i < MAX; ++i) {
        if(prime[i]) continue;
        for(int j = i; j <= MAX; j += i) {
            if(!prime[j]) prime[j] = i;
        }
    }
}

void set_num(Power *mpow, int a, int b) {
    int len, x, num = 0;
    while(a != 1) {
        len = 0, x = prime[a];
        while(a % x == 0) {
            len++;
            a /= x;
        }
        mpow[num].a = x;            //底赋值
        mpow[num].n = len * b;      //幂次赋值 
        num++;
    }
}
int main() {
    init();
    for(int a = 2; a <= 100; ++a) {
        for(int b = 2; b <=100; ++b) {
            Power mpow[4] = {0};
            set_num(mpow, a, b);
            int flag = 1;
            for(int i = 0; i < M_sum && flag; ++i) {       //比较有无相同分解
                flag = memcmp(mpow, mix[i], sizeof(mpow)); 
            }
            if(flag) {                                      //没有添加进数组
                memcpy(mix[M_sum++], mpow, sizeof(mpow));

            }
        }
    }
    printf("%d\n", M_sum);
    
    
    return 0;
}
