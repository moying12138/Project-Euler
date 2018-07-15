/*************************************************************************
	> File Name: 26.c
	> Author: moying
	> Mail: 
	> Created Time: 2018年05月08日 星期二 16时16分10秒
 ************************************************************************/

#include<stdio.h>

int get(int x) {
    int i = 1,len = 1;
    int num[1000] = {0};
    do{
        i = (i * 10) % x;
        if(num[i]) break;
        num[i] = len++;
    }while(i);
    return len - num[i];
    
    
}
int get_2(int x) {
    int i = 1, len = 1;
    int num[1000] =  {0};
    do{
        num[i] = (len++);
        i =(i * 10) % x;
    }while(i && !num[i]);
    if(!i) return 0;
    return len - num[i];
}
int get_3(int x) {
    int a = 1, b = 1;
    do{
        a = (a * 10) % x;  //走一步
        b = (b * 10) % x;  //b走两步
        b = (b * 10) % x;
    }while(b && a != b);    // a追上b时说明有循环，等于0没循环
    if(!b) return 0;
    int sum = 0;
    do{
        b = (b * 10) % x;  //a不动，b开始走
        sum++;             
    }while(a != b);        //直到b又一次追上a结束
    return sum;
}
int main() {
    int n;
    int res = 0, x, y = 0;
    for(int i = 2; i < 1000; ++i) {
        x = get_3(i);
        if(x > y) {
            res = i;
            y = x;
        }
    }
    printf("%d  %d\n", res, y);
    
    return 0;
}
