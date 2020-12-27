/*************************************************************************
	> File Name: 20.newton.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 04:37:33 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>

double F(double x, double n){
    return x * x - n;
}

double f(double x){
    return 2 * x;
}

double NewTon(double (*F)(double, double), double (*f)(double), double n ){
    double x = n / 2.0;
    #define EPSL 1e-6
    while(fabs(F(x,n)) > EPSL){
        x -= F(x, n) / f(x);
    }
    #undef EPSL
    return x;
}

double my_sqrt(double n){
    return NewTon(F, f, n);
}

int main(){
    double n;
    while(~scanf("%lf",&n)){
        printf("%g\n",my_sqrt(n));
    }
    return 0;
}
