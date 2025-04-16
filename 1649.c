#include <stdio.h>
#include <stdlib.h>
 
#define MS 5
 
typedef struct Que{
    int data[MS];
    int rear;
    int front;
}que;
 
void init(que *q){
    q->front = q->rear = 0;
}
 
int is_full(que *q){
    return q->front == (q->rear + 1) % MS;
}
 
int is_empty(que *q){
    return q->front == q->rear;
}
 
int deque(que *q){
    if(is_empty(q)) return -999;
    q->front = (q->front +1) % MS;
    return q->data[q->front];
}
 
void enque(que *q, int v){
    if(is_full(q)){
        deque(q);
    }
    q->rear = (q->rear + 1) % MS;
    q->data[q->rear] = v;
}
 
int main(void){
    que q;
    init(&q);
    int ctt;
    while(1){
        scanf("%d",&ctt);
        if(ctt> 0) enque(&q, ctt);
        else if (ctt == 0){
            printf("%d", deque(&q));
            return 0;
        }
        else if (ctt == -1) deque(&q);
    }
return 0;
}