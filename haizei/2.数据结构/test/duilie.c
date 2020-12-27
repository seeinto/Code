/*************************************************************************
	> File Name: duilie.c
	> Author: 
	> Mail: 
	> Created Time: Mon 23 Nov 2020 04:57:46 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int *data;
    int head, tail, length;
}Queue;

Queue *init(int n){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->head = q->tail = q->length =  0;
    return q;
}

int out(Queue *q){
    if (q == NULL)return 0;
    q->head++;
    return 1;
}

int up(Queue *q, int value){
    if(q == NULL)return 0;
    q->data[q->tail++] = value;
    return 1;
}

void clear(Queue *q){
    if(q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}


int main(){
    int n, m;
    scanf("%d", &n);
    Queue *q = init(n);
    while(n--){
        scanf("%d", &m);
        up(q, m);
    }
    while(q->head < q->tail){
        printf("%d ",q->data[q->head]);
        out(q);
        up(q, q->data[q->head]);
        out(q);
    }
    printf("\n");
    return 0;
}
