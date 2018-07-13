/*************************************************************************
	> File Name: 11.c
	> Author: moying 
	> Mail: 
	> Created Time: 2018年05月01日 星期二 20时06分46秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int a[20][20];
    for(int i = 0; i < 20; ++i) {
        for(int j = 0 ; j < 20; ++j) {  //重定向文件11_in当作此程序的标准输入 ./a.out < 11_in
            scanf("%d", a[i] + j);
        }
    }
    int ans = 0;
    int f[4][2] = {0,1,1,0,1,1,-1,1}; //控制4个方向
    for(int i = 0; i < 20; ++i) {
        for(int j = 0; j < 20; ++j) {
            for(int k = 0; k < 4; ++k) {
                int tmp = 1;
                int x1,x2;
                for(int l = 0; l < 4; ++l) {
                    x1 = i + f[k][0] * l;
                    x2 = j + f[k][1] * l;
                    if(x1 < 0 || x2 < 0) {tmp = -1; break;}  
                    if(x1 >=20 || x2 >= 20) {tmp = -1; break;}
                    tmp *= a[x1][x2];
                }
                if(tmp > ans) ans = tmp;
            }

        }
    }
    printf("%d\n", ans);
    return 0;
}
