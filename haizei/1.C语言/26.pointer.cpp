/*************************************************************************
	> File Name: 26.pointer.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 02:29:41 PM CST
 ************************************************************************/

#include <stdio.h>
#define offser(T, a) (long)(&(((T *)(NULL)))->a)
struct Data {
    int a;
    double b;
    char c;
};

int main(){
    int num1 = 0x616263;
    int num2 = 0x61626364;
    printf("%s\n",(char *)(&num2));
    printf("%ld\n",offser(struct Data, a));
    printf("%ld\n",offser(struct Data, b));
    printf("%ld\n",offser(struct Data, c));
    return 0;
}
