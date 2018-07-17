/*************************************************************************
	> File Name: 35.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年04月25日 星期三 18时30分55秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define f(a) ((int)log10(a))
#define MAX 1000000
int cir[MAX] = {0};
int sum = 0;
void is_cir(int n) {
    int w = (int)log10(n);
    for(int i = 0; i < w; ++i)  {
        int x = (n / pow(10, w));
        n = (n %(int)pow(10, w)) * 10 + x;
        if(cir[n]) return ;
        //printf("%d ", n);
        //cir[n] = 1;
    }
    printf("%d , %d\n", n, sum);
    sum += 1;
}
void is_cir2(int n) {
    int w = f(n);
    for(int i = 0; i < w; ++i) {
        int x = n % 10;
        n = (n / 10) + x * (int)pow(10,w); //最后一位 移动到第一位
        if(cir[n]) return;
    }
    sum++;
}
int main() {
    for(int i = 2; i * i < MAX; ++i) {  //素数筛
        if(!cir[i]) {
            for(int j = i * i; j < MAX; j += i) {
                cir[j] = 1;
            }
        }
    }

    for(int i = 2; i < MAX; ++i) {
        //if(i == 11) sum++;
        if(!cir[i])
        is_cir2(i);
    }
    printf("%d\n", sum);
    return 0;
}
