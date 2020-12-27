/*************************************************************************
	> File Name: 15.prime.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 03:53:12 PM CST
 ************************************************************************/

#include <stdio.h>
#define max 100
int prime[max + 5];

void init(){
    for(int i = 2; i <= max; i++){
        if(prime[i])continue;
        prime[++prime[0]] = i;
        for(int j = i * i ; j <= max;j +=i){
            prime[j] = 1;
        }
    }
    return ;
}

int main(){
    init();
    int sum = 0;
    for(int i = 1; i <= prime[0]; i++){
       sum += prime[i];
        printf("%d\n",prime[i]);
    }
    printf("%d\n",sum);
    return 0;
}
