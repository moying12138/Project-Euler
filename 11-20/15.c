/*************************************************************************
	> File Name: 15.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年07月13日 星期五 22时35分49秒
 ************************************************************************/

#include<stdio.h>

 int main() {
    long ans = 1, m = 20;
    for (int i = 40; i > 20; --i) {
        ans *= i;
        while (ans % m == 0 && m != 1) {
            ans /= m;
            --m;
        } 
    }
    printf("%ld\n", ans);
    return 0;
}
