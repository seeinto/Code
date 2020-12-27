/*************************************************************************
	> File Name: 18.binart_search.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 04:10:05 PM CST
 ************************************************************************/

#include <stdio.h>

//1 2 3  4  5  6  7  8  9
//1 4 9 16 25 36 49 64 81
int func(int x){
    return x * x;
}

int binary_search(int (*arr)(int), int n,int x){
    int head = 0, tail = n - 1, mid;
    while(head <= tail){
        mid = (head + tail) >> 1;
        if(arr(mid) == x)return mid;
        if(arr(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int main(){
    int n;
    while(~scanf("%d",&n)){
        int x = binary_search(func,n,n);
        printf("%d * %d = %d\n", x, x, n);
    }
    return 0;
}
