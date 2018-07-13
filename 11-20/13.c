/*************************************************************************
	> File Name: 13.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年05月01日 星期二 20时43分56秒
 ************************************************************************/

#include<stdio.h>
char a[55] = {0};
int sum[55] = {0};
int main() {
    while(scanf("%s", a) != EOF) {  //类似前面11题的重定向 每一行处理 ./a.out < 13_in
        for(int i = 49; i >= 0; --i) {
            sum[50 - i] += a[i] - '0';
        }
    }
     sum[0]= 50;                    //50个数相加不可能超int所以可以每一位加完再处理进位，初始为50个数
    for(int i = 1; i <= sum[0]; ++i) {
        if(sum[i] < 10) continue;
        sum[i + 1] += sum[i] / 10;
        sum[i] %= 10;
        sum[0] += (i == sum[0]);    //最高位进位时，位数加1,否则加0(不变)
    }
    for(int i = sum[0]; i > sum[0] - 10; --i) {  //输出前10位
        printf("%d ", sum[i]);
    }
    printf("\n");
    return 0;
}
