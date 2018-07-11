/*************************************************************************
	> File Name: 1.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年04月15日 星期日 15时43分04秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define NUM 600851475143
int main() {
    long tmp = 0;
    long num = NUM;
    for(long i = 2; i < num; ++i) {
        while(num % i == 0) {
            num /= i;
            tmp = i;
        }
    }
    printf("%ld\n", tmp < num ? num : tmp);
    return 0;
}
