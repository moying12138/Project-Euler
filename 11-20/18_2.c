/*************************************************************************
	> File Name: 18_teach_move.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年04月29日 星期日 20时12分58秒
 ************************************************************************/

#include<stdio.h>
#define MAX 100
int map[MAX][MAX] = {0};
int f[MAX][MAX] = {0};

int main() {
    int n ;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    for(int i = 0; i < n; ++i) {
        f[n - 1][i] = map[n - 1][i];   //初始化为map的最后一行值
    }
    for(int i = n - 2; i >= 0; --i) {
        for(int j = 0; j <= i; ++j) { //从下到上求路径最大和
            f[i][j] = map[i][j];
            if(f[i + 1][j] > f[i + 1][j + 1]) { 
                f[i][j] += f[i + 1][j];
            } else {
                f[i][j] += f[i + 1][j + 1];
            }
        }
    }
    printf("%d", f[0][0]);
    return 0;
}
