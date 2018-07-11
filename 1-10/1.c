/*************************************************************************
	> File Name: 1.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年04月16日 星期一 15时24分31秒
 ************************************************************************/

#include<stdio.h>
int two_number_mul_sum(int a, int b, int max) {
    int sum = 0;
    --max;
    sum += (a + (max / a) * a) * (max / a) / 2;//所有a的倍数和
    sum += (b + (max / b) * b) * (max / b) / 2;//所有b的倍数和
    if(a * b <= max){  //如果ab最小倍数小于max，则减去重复项
        sum -= (a * b + max / (a * b) * (a * b)) * (max / (a * b)) / 2;
    }
    //printf("%d\n",1005 * max / (a * b) / 2);
    return sum;
}
int main() {
    int a, b, max;
    scanf("%d %d %d", &a, &b, &max);//输入max以内的a和b的倍数和，示例输入 3 5 1000
    int res = two_number_mul_sum(a, b, max);
    printf("%d\n", res);
    return 0;
}
