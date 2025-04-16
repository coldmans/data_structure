#include <stdio.h>
 
#define SIZE 20
 
int queue[SIZE];
int front = -1, rear = -1;
 
void enqueue(int val) {
    if (rear < SIZE - 1) queue[++rear] = val;
}
 
int dequeue() {
    if (front < rear) return queue[++front];
    return -1;
}
 
int is_empty() {
    return front == rear;
}
 
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == -1) dequeue();
        else if (n == 0) {
            if (!is_empty())
                printf("%d", queue[front + 1] + queue[rear]);
            else
                printf("-999");
            break;
        } else {
            enqueue(n);
        }
    }
    return 0;
}