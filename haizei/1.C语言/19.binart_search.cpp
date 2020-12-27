/*************************************************************************
	> File Name: 19.binart_search.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 04:23:28 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>

double func(double x){
        return x * x;

}

double binary_search(double (*arr)(double),double x){
    double head = 0, tail = x, mid;
    if(x < 1.0)tail = 1.0;
    #define EPFL 1e-7    
    while(tail - head > EPFL){
        mid = (head + tail) / 2.0;
        if(arr(mid) < x) head = mid;
        else tail = mid;
    }
    #undef EPFL
    return head;

}

int main(){
        double n;
    while(~scanf("%lf",&n)){
        printf("my_sqrt(%g) = %g\n", n, binary_search(func, n));
        printf("sqrt(%g) = %g\n", n, sqrt(n));
    }
        return 0;

}

