/*************************************************************************
	> File Name: 44.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年04月29日 星期日 10时33分29秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX 3000
#define MAX_MAX 100000000
int xx[MAX_MAX + 5] = {0};
long p[MAX + 5] = {0};
void init() {   //初始化所有5边形数
    for(int i = 1; i < MAX; ++i) {
        p[i] = i * (3 * i - 1) >> 1;
        xx[p[i]] = 1;
    }
}
void print() {
    for(int  i = 0; i < MAX; i++) {
        printf("%ld ", p[i]);
    }
}
int binary_seach(int n) { //二分查找
    int min = 1;
    int max = MAX - 1;
    int mid;
    while(min <= max) {
        mid = (min + max) >> 1;
        if(n < p[mid]) max = mid - 1;
        else if(n > p[mid]) min = mid + 1;
        else return 1;
        
    }
    return 0;
}
int main() {
    init();
    int min = 100000000;
     for(int i = 1; i < 10000; ++i) {
        for(int j = i - 1; j >= 1; j--) {
            if(p[i] - p[j] >= min) break; //提前结束循环
            //if(binary_seach(p[j] + p[i]) && binary_seach(p[i] - p[j])) {
            //if(p[i] + p[j] > MAX_MAX) printf("ssss");
            if(xx[p[j] + p[i]] && xx[p[i] - p[j]]){
                printf("%d %d\n", i, j);
                if(min > p[i] - p[j])
                min = p[i] - p[j];
                printf("%d\n", min);
                return 0;
                break;
            }
        }
    }
    return 0;
}
