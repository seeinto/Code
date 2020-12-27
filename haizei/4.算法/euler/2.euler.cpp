/*************************************************************************
	> File Name: 2.euler.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Dec 2020 06:39:16 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//int num[1000000];

int main() {
  /*  num[1] = 1, num[2] = 2;
    for (int i = 3; 1; i++) {
        num[i] = num[i - 1] + num[i - 2];
        if (num[i] >= 4000000)break;
    }
    long long ans = 0;
    for (int i = 1; 1; i++) {
        if(num[i] % 2 == 0) {
            ans += num[i];
        }
        if (num[i] >= 4000000)break;
    }
    cout << ans << endl; */

    int a = 1, b = 2, ans = 0;
    while (b <= 4000000) {
        if (b % 2 == 0) {
            ans += b;
        }
        b = a + b;  //b  2  3  5  8      
        a = b - a;  //a  1  2  3  5
    }
    cout << ans << endl; 
    return 0;
}
