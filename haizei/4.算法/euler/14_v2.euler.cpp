/*************************************************************************
	> File Name: 14_v2.euler.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Dec 2020 08:52:49 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int num[1000000];

int func(long long n) {
    if (n == 1) return 1;
    if (n < 1000000 && num[n]) return num[n];
    int t;
    if (n % 2 == 0) t = func(n / 2) + 1;
    else t = func(3 * n + 1) + 1;
    if (n < 1000000) {
        num[n] = t;
    }
    return t;
}

int main() {
    int ans = 1;
    for (int i = 2; i < 1000000; i++) {
        if(func(ans) < func(i)) {
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
