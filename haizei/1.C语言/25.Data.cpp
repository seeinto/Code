/*************************************************************************
	> File Name: 25.Data.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 02:10:09 PM CST
 ************************************************************************/

#include <stdio.h>
#define P(a){\
    printf("%s = %d\n",#a, a);\
}

struct Data{
    int x, y;
};

int main(){
    struct Data a[2], *p = a;
    a[0].x = 1, a[0].y = 1;
    a[1].x = 2, a[1].y = 2;
    P(a[1].x);
    P((a + 1)->x);
    P((p + 1)->x);
    P(p[1].x);
    P((*(p + 1)).x);
    P((*(a + 1)).x);
    return 0;

}
