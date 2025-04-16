#include <stdio.h>
#define SIZE 6
int queue[SIZE];
int front = 0, rear = 0;
 
int is_empty() { return front == rear; }
int is_full() { return (rear + 1) % SIZE == front; }
 
void enqueue(int val) {
    if (!is_full()) {
        rear = (rear + 1) % SIZE;
        queue[rear] = val;
    }
}
 
void dequeue() {
    if (!is_empty()) {
        front = (front + 1) % SIZE;
    }
}
 
int main() {
    int i;
 
    while (1) {
        scanf("%d", &i);
        if (i > 0)
            enqueue(i);
        else if (i < 0)
            dequeue();
        else if (i == 0)
            break;
    }
 
    int k = (front + 1) % SIZE;
    while (k != (rear + 1) % SIZE) {
        printf("%d ", queue[k]);
        k = (k + 1) % SIZE;
    }
 
    return 0;
}