/*************************************************************************
	> File Name: 2.list.c
	> Author: 
	> Mail: 
	> Created Time: Tue 17 Nov 2020 02:50:58 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

typedef struct ListNode{
    int data;
    struct ListNode *next;
}ListNode;

typedef struct List{
    ListNode head;
    int length; 
}List;

ListNode *getNewNode(int);
List *getNewlist();
void clear_node(ListNode *);
void clear(List *);
int insert(List *, int, int);
int erase(List *, int);
void reverse(List *l);
void output(List *);

int main(){
    srand(time(0));
    #define max 20
    List *l = getNewlist();
    for(int i = 0; i < max; i++){
        int val = rand() % 100;
        int ind = rand() % (l->length + 3) - 1;
        int op = rand() % 4;
        switch (op){
            case 0:
            case 1: {
                printf("insert %d at %d to List = %d\n", val , ind, insert(l, val, ind));
            }break;
            case 2:{
                printf("erase iterm at %d from List = %d\n",ind, erase(l, ind));
            }break;
            case 3:{
                printf(GREEN("reverse the List !") "\n");
                reverse(l);
            }break;
        }
        output(l);
        printf("\n");
    }
    #undef max
    clear(l);
    return 0;
}

ListNode *getNewNode(int val){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

List *getNewlist(){
    List *l = (List *)malloc(sizeof(List));
    l->length = 0;
    l->head.next = NULL;
    return l;
}

int insert(List *l, int val, int ind){
    if(l == NULL)return 0;
    if(ind < 0 || ind > l->length)return 0;
    ListNode *p = &(l->head), *node = getNewNode(val);
    while(ind--) p = p->next;
    node->next = p->next;
    p->next = node;
    l->length++;
    return 1;
}

int erase(List *l, int ind){
    if(l == NULL) return 0;
    if(ind < 0 || ind >= l->length) return 0;
    ListNode *p = &(l->head), *q;
    while(ind--)p = p->next;
    q = p->next; 
    p->next = q->next;
    free(q);
    l->length--;
    return 1;
}

void reverse(List *l){
    if(l == NULL) return ;
    ListNode *p = l->head.next, *q;
    l->head.next = NULL;
    while(p){
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return ;
}

void output(List *l){
    if(l == NULL)return ;
    printf("List(%d) = [", l->length);
    for(ListNode *p = l->head.next; p; p = p->next){
        printf("%d->",p->data);
    }
    printf("NULL]\n");
    return ;
}

void clear_node(ListNode *node){
    if(node == NULL)return ;
    free(node);
    return ;
}

void clear(List *l){
    if(l == NULL) return ;
    ListNode *p = l->head.next, *q;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    free(l);
    return ;
}


