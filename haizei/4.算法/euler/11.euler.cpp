/*************************************************************************
	> File Name: 11.euler.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Dec 2525 08:09:37 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int ans;
int num[30][30];
int dirx[4] = {-1,0,1,1};
int diry[4] = { 1,1,1,0};

int main() {
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            cin >> num[i][j];       //输入数列
        }
    }
    for (int i = 5; i < 25; i++) {    //数组行
        for (int j = 5; j < 25; j++) { //数组列
            for (int k = 0; k < 4; k++) { //4个坐标
                int t = num[i][j];        //t为原始数字
                for (int l = 1; l < 4; l++) { //l为偏移的位数
                    int x = i + dirx[k] * l;  //移动X坐标
                    int y = j + diry[k] * l;  //移动Y坐标
                    t *= num[x][y];           //偏移数相乘
                }
                ans = max(ans,t);             //更新最大值
            }
        }
    }
   cout << ans <<endl;

    return 0;
}
