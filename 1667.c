#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 6
 
typedef struct Queue {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
}Queue;
 
void init_que(Queue *q) {
    q->front = q->rear = 0;
}
 
int is_full(Queue* q) {
    return q->rear == MAX_QUEUE_SIZE-1;
}
 
int is_empty(Queue* q) {
    return q->front == q->rear;
}
 
void enqueue(Queue* q, int v) {
    if (is_full(q))
        return;
    q->rear = q->rear + 1;
    q->data[q->rear] = v;
}
 
void dequeue(Queue* q) {
    if (is_empty(q))
        return;
    q->front = q->front + 1;
}
 
void printQueue(Queue* q) {
    while (1) {
        if (is_empty(q))
            return;
        printf("%d ", q->data[++(q->front)]);
    }
}
 
int main(void) {
    int i;
    Queue q;
    init_que(&q);
 
    while (1) {
        scanf("%d", &i);
        if (i == -1 && !is_empty(&q))
            dequeue(&q);
        else if (i == 0) {
            if (is_empty(&q)) {
                printf("-999");
                return 0;
            }
            while (1) {
                if (is_empty(&q))
                    return 0;
                printQueue(&q);
            }
        }
        else if (i > 0 && !is_full(&q)) {
            enqueue(&q, i);
        }
    }
 
    return 0;
}