/*************************************************************************
	> File Name: 31.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年04月25日 星期三 11时11分28秒
 ************************************************************************/

#include<stdio.h>
int money[9] = {0,1,2,5,10,20,50,100,200};
int kind[9][1005] = {0};
int money_kind(int k, int n) {
    if(k == 1) return 1;
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(!kind[k][n]){
        kind[k][n] = money_kind(k - 1, n) + money_kind(k, n - money[k]);
    }
    return kind[k][n];
}
int main() {
    int n;
    //scanf("%d", &n);
    printf("%d\n", money_kind(8,1000));
    return 0;
}

