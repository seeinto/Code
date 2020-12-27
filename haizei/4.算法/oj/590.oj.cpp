/*************************************************************************
	> File Name: 590.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Dec 2020 08:38:50 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int n, m, num[1005][1005], utd[1005][1005], dtu[1005][1005],ans[1005][1005],mmax[1005],sec[1005];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            utd[i][j] = max(utd[i - 1][j - 1], utd[i - 1][j]) + num[i][j];
        }
    }
     for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            dtu[i][j] = max(dtu[i + 1][j], dtu[i + 1][j + 1]) + num[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            ans[i][j] = utd[i][j] + dtu[i][j] - num[i][j];
        }
    }
    for (int i = 2; i <= n; i++) {
        int m1 = 0, m2 = 0, ind = 0;
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] > m1) {  //更新最大值
                m2 = m1;
                m1 = ans[i][j];
                ind = j;
            } else if (ans[i][j] > m2 ) {  //更新次大值
                m2 = ans[i][j];
            }
        }
        mmax[i] = ind; //最大值坐标
        sec[i] = m2;  //次大值 
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x,&y);
        if (x == 1) {
            printf("-1\n");
        }else if(y == mmax[x]) {
            printf("%d\n",sec[x]);
        } else {
            printf("%d\n",dtu[1][1]);
        }
    }
   return 0;
}
