/*************************************************************************
	> File Name: 475.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 27 Dec 2020 09:24:58 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

char num1[1005],num2[1005];
int ans[1005], tmep[1005];

int main() {
    cin >> num1 >> num2;
    ans[0] = max(strlen(num1), strlen(num2));
    
    for (int i = 1; i <= ans[0]; i++) {

    }


    for (int i = ans[0]; i > 0; i--) {
        cout << ans[i];    
    }
        cout << endl;
    return 0;

}
