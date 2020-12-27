/*************************************************************************

	> Author: 
	> Mail: 
	> Created Time: Wed 18 Nov 2020 01:53:56 PM CST
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

typedef struct Queue{
    int *data;
    int head, tail, lenght,cont;
}Queue;

Queue *init(int n){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->head = q->tail = q->cont  =  0;
    q->lenght = n;
    return q;
}

int front(Queue *q){
    return q->data[q->head];
}

int empty(Queue *q){
    return q->cont == 0;
}

int expand(Queue *q){
    int ex_size = q->lenght;
    int *p;
    while(ex_size){
        p = (int *)malloc(sizeof(int) * (q->lenght + ex_size));
        if(p)break;
        ex_size >>= 1;
    }
    if(p == NULL)return 0;
    for(int i = q->head, j = 0; j < q->cont; j++){
        p[j] = q->data[(i + j) % q->lenght];
    }
    free(q->data);
    q->data = p;
    q->lenght += ex_size;
    q->head = 0;
    q->tail = q->cont;
    return 1;
}

int push(Queue *q, int val){
    if(q == NULL)return 0;
    if(q->cont == q->lenght){
        if(!expand(q))return 0;
        printf(GREEN("expand successfully ! Queue->size(%d)")"\n", q->lenght);
    }
    q->data[q->tail++] = val;
    if(q->tail == q->lenght) q->tail = 0;
    q->cont += 1;
    return 1;
}

int pop(Queue *q){
    if(q == NULL)return 0;
    if(empty(q))return 0;
    q->head++;
    if(q->head == q->lenght)q->head = 0;
    q->cont -= 1;
    return 1;
}

void output(Queue *q){
    printf("Queue : [");
    for(int i = q->head, j = 0; j < q->cont; i++, j++){
        j && printf(", ");
        printf("%d",q->data[i % q->lenght]);
    }
    printf("]\n");
    return ;
}

void clear(Queue *q){
    if(q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main(){
    srand(time(0));
    #define max 20
    Queue *q = init(5);
    for(int i = 0; i < max; i++){
        int val = rand() % 100;
        int op = rand() % 4;
        switch(op){
            case 0:
            case 1:
            case 2:{
                printf("push %d to the Queue = %d\n", val, push(q, val));
            }break;
            case 3:{
                printf("pop %d from the Queue = %d\n", front(q), pop(q));
            }break;
        }
        output(q),printf("\n");
    }
    #undef max
    clear(q);
    return 0;
}
