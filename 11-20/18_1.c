/*************************************************************************
	> File Name: 18_teach.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年04月29日 星期日 19时17分15秒
 ************************************************************************/

#include<stdio.h>
#define MAX 100
int map[MAX][MAX] = {0}; //储存重定向数据  ./a.out < 18_in
int f[MAX][MAX] = {0};   //记录当前路径最大和

int dfs(int i, int j, int n) {   //记忆数组
    if(i == n) return 0;
    if(!f[i][j]) {
        int ans = dfs(i + 1, j, n) ;
        int ans1 = dfs(i + 1, j + 1, n);
        f[i][j] = (ans > ans1 ? ans : ans1) + map[i][j]; 
    }
    return f[i][j];
}

int main() {
    int n ;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            scanf("%d", map[i] + j);
        }
    }
    printf("%d\n", dfs(0, 0, n));
    return 0;
}
