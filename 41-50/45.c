/*************************************************************************
	> File Name: 45.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年04月29日 星期日 14时39分38秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int64_t Pentagonal(int64_t n ) { //五边形数
    return n * (3 * n - 1) >> 1;
}


int binary_search(int64_t n, int64_t (*f)(int64_t)) {
    int64_t head  = 1, tail = n, mid;
    int64_t x;
    while(head <= tail) {
        mid = (head + tail) >> 1;
        x = f(mid);
        if(x == n) return 1;
        if(x > n) tail = mid - 1;
        else head = mid + 1;
    }
    return 0;
}
int main() {
    int64_t n = 144;
    while(!binary_search(n * (2 * n - 1), Pentagonal)) ++n; //是六边形一定是三角形数所以只遍历六边形数
    printf("%"PRId64"\n", n * (2 * n - 1)); 
    return 0;
}
