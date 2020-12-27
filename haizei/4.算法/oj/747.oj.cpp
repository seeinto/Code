/*************************************************************************
	> File Name: 747.oj.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 27 Dec 2020 03:02:20 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

char num1[1005],num2[1005];
int n1[1005],n2[1005],ans[1005];

int main() {
    int a, b, cnt = 0;
    cin >> a >> b;
    cin >> num1 >> num2;
    n1[0] = strlen(num1);
    n2[0] = strlen(num2);
    ans[0] = max(a, b);
    for (int i = 1, j = n1[0] - 1; i <= n1[0]; i++, j--) {
        n1[i] =  num1[j] - '0';   
    }

    for (int i = 1, j = n2[0] - 1; i <= n2[0]; i++, j--) {
        n2[i] =  num2[j] - '0';    
    }
    
    if (a < b || num1[0]  < num2[0]) {
        swap(n1, n2);
        cnt = 1;
    }

    for (int i = 1; i <= ans[0]; i++) {
        ans[i] = n1[i] - n2[i];
    } 
    
    for(int i = 1; i <= ans[0]; i++) {
        if (i == ans[0]) break;
        if (ans[i] < 0) {
            ans[i] += 10;
            ans[i + 1] -= 1;
        }
    }
    
    if (cnt) ans[ans[0]] *= -1;

    for (int i = ans[0]; i > 0; i--) {
        if (ans[i] == 0 )continue;
        else {
            cnt = i;
            for (int j = cnt; j > 0; j--) {
                cout << ans[j];
            }
        }
        break;
    }
    cout << endl;
    return 0;

}
