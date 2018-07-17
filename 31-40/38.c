/*************************************************************************
	> File Name: 38.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年04月25日 星期三 20时12分12秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define f(a) ((int)(log10(a) + 1))
int is_allnum(int a, int *num) {
    while(a) {
        if(a % 10 == 0 || num[a % 10]) return 0;
        num[a % 10] = 1;
        a /= 10;
    }
    return 1;
}
int is_all(int a) {
    int num[10] = {0};
    int num_sum = 0;
    int i;
    for( i = 1; i < 10; ++i) {
        if(num_sum < 9 && is_allnum(a * i, num)) {
            num_sum += f(a * i);
        } else{
            break;
        }
    }
    if(num_sum == 9) {
        int sum = 0;
        int n = 9;
        for(int j = 1; j < i; ++j) {
            int x = a * j;
            n -= f(x);
            sum += x * (int)pow(10, n);
        }
        return sum;
    } else {
        return 0;
    }
    
    
}
int main() {
    int sum = 0;
    int size = 10000;
    for(int i = 10000; i > 1; --i) {
        
        int x = is_all(i);
        if(x) {
            printf("%d\n", x);
            if(x > sum) {
                sum = x;
            }
            i = size / 10;         //每次从大到小筛，筛出一个说明在这个区间是最大的了，前往下个区间
            size /= 10;            //区间缩小
        }
    }
    printf("max -- %d\n", sum);
    return 0;
}
