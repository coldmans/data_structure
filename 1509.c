#include <stdio.h>
#define SIZE 6
 
int q[SIZE], front = 0, rear = 0;
 
int is_full() { return (rear + 1) % SIZE == front; }
int is_empty() { return front == rear; }
 
void enqueue(int val) {
    if (!is_full()) {
        rear = (rear + 1) % SIZE;
        q[rear] = val;
    }
}
 
int dequeue() {
    if (!is_empty()) {
        front = (front + 1) % SIZE;
        return q[front];
    }
    return -1;
}
 
int main() {
    int x;
    while (1) {
        scanf("%d", &x);
        if (x > 0) enqueue(x);
        else if (x == -1) {
            int temp = dequeue();
            if (temp != -1) enqueue(temp);
        }
        else if (x == -999) {
            while (!is_empty()) {
                int temp = dequeue();
                printf("%d", temp);
                if (!is_empty()) printf(" ");
            }
            break;
        }
    }
    return 0;
}