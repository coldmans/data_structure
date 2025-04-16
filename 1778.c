#include <stdio.h>
#include <stdlib.h>
 
#define MS 6
 
typedef struct{
    int data[MS];
    int rear, front;
}Que;
 
int is_full(Que *q){
    return q->front == (q->rear +1) % MS;
}
 
int is_empty(Que *q){
    return q->front == q->rear;
}
 
void init(Que *q){
    q->front = q->rear = 0;
}
 
void enque(Que *q, int v){
    if(is_full(q)) return;
    q->rear = (q->rear +1 ) % MS;
    q->data[q->rear] = v;
    return;
}
 
int deque(Que *q){
    if(is_empty(q)) return 0;
    q->front = (q->front +1) % MS;
    return q->data[q->front];
}
 
int main(void){
    int a;
    int tmp;
    Que q;
    init(&q);
    while(1){
        scanf("%d", &a);
        if(a > 0) enque(&q, a);
        else if(a == -1){
            if(!is_empty(&q)){
            tmp = deque(&q);
            enque(&q, tmp);
            }
        }
        else if(a == -999){
            while(1){
                if(is_empty(&q))
                    return 0;
                printf("%d ", deque(&q));
            }
        }
    }
     
    return 0;
}