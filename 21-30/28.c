/*************************************************************************
	> File Name: 28.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年07月15日 星期日 12时19分00秒
 ************************************************************************/

#include <stdio.h>
int main() {  
    int sum = 1, len = 3;
    while (len <= 1001) {
        sum += 4 * len * len - 6 * len + 6;
        len += 2;
    }
    printf("%d\n", sum);
    return 0;
 }
