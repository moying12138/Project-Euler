/*************************************************************************
	> File Name: 8x.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年04月22日 星期日 11时13分00秒
 ************************************************************************/

#include<stdio.h>
#include"8.h"

int main() {
    long res, zero,  max;
    res = 1;
    zero = max = 0;
    for(int i = 0; i < 1000; ++i) {
        if(a[i] != '0') {
            res *= a[i] - '0';
        } else {
            ++zero;
        }
        if(i >= 13) {
            if(a[i - 13] != '0'){
                res /= a[i - 13] - '0';
            } else {
                --zero;
            }
        }
        if(!zero && res > max) max = res;
    }
    printf("%ld\n", max);









    //char str[2000];
    //int i = 0;
   // while(scanf("%s", str+i) != EOF) {
     //   i += printf("%s", str);
    //}
    //scanf("s[^EOF]", str);
    //printf("%s", str);
    //sscanf(a, "%s")
    return 0;

}
