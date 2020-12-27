/*************************************************************************
	> File Name: 4.Stack.c
	> Author: 
	> Mail: 
	> Created Time: Wed 18 Nov 2020 04:32:09 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack{
    int *data;
    int size, top;
}Stack;

Stack *init(int);
void clear(Stack *);
int top(Stack *);
int empty(Stack *);
int push(Stack *, int);
int pop(Stack *);
void output(Stack *);

int main(){
    srand(time(0));
    #define max 20
    Stack *s = init(max);
    for(int i = 0; i < max; i++){
        int val = rand() % 100;
        int op = rand() % 4;
        switch(op){
            case 0:
            case 1:
            case 2: {
                printf("push %d to the Stack = %d\n", val, push(s, val));
            }break;
            case 3: {
                printf("pop %d from the Stack = %d\n", top(s), pop(s));
            }break;
        }
        output(s), printf("\n");
    }
    #undef max
    clear(s);
    return 0;
}

Stack *init(int n){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

void clear(Stack *s){
    if(s == NULL)return ;
    free(s->data);
    free(s);
    return;
}

int top(Stack *s){
    return s->data[s->top];
}

int empty(Stack *s){
    return s->top == -1;
}

int push(Stack *s, int val){
    if(s == NULL) return 0;
    if(s->top == s->size - 1)return 0;
    s->data[++(s->top)] = val;
    return 1;
}

int pop(Stack *s){
    if(s == NULL) return 0;
    if(empty(s)) return 0;
    s->top -= 1;
    return 1;
}

void output(Stack *s){
    printf("Stack(%d) = [", s->top + 1);
    for(int i = 0; i <= s->top; i++){
        i && printf(", ");
        printf("%d", s->data[i]);
    }
    printf("]\n");
    return ;
}
