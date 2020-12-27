/*************************************************************************
	> File Name: 449.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 27 Dec 2020 05:39:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int n,num[1000][1000];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
    num[i][1] = 1;        
    }
        
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= i; j++) {
        num[i][j] += num[i - 1][j - 1] + num[i - 1][j];            
        }
    }
        
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            j != 1 && cout << " ";
            cout << num[i][j];        
        }
        cout << endl;
    }

    return 0;

}
