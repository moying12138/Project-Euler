/*************************************************************************
	> File Name: 43.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年04月29日 星期日 09时49分02秒
 ************************************************************************/

#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int prime[8] = {0,2,3,5,7,11,13,17}; 
int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}
long check(int *a) {
    int j = 1;
    long sum = 0;
    for(int i = 1; i < 8; i++){
        sum = a[i] * 100 + a[i + 1] * 10 + a[i + 2];
        if(sum % prime[j] == 0) {
            j++;
        } else {
            return 0;
        }
    }
    sum = 0;
    for(int i = 0; i < 10; ++i) {
        sum = sum * 10 + a[i];
    }
    return sum;
}
int main() {
    int a[10] = {0};
    long sum = 0;
    for(int i = 0; i < 10; ++i) {  
        a[i] = i;
    }
    do {
        sum += check(a);
    }while(next_permutation(a, a + 10)); //生成下一个字典序
    cout << sum << endl;
    return 0;
}
