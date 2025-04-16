#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5
 
int top = -1;
int data[MAX_STACK_SIZE];
 
int is_full() {
    return top == MAX_STACK_SIZE - 1;
}
 
int is_empty() {
    return top == -1;
}
 
void push(int v) {
    if (!is_full()) {
        data[++top] = v;
    }
    return;
}
 
int pop() {
    if (!is_empty()) {
        return data[top--];
    }
    return 0;
}
 
int main(void) {
    int ctt;
    int result = 0;
    while (1) {
        scanf("%d", &ctt);
        if (ctt > 0)
            push(ctt);
 
        else if (ctt == -1) {
            while (1) {
                if (top == -1)
                    break;
                result += pop();
            }
            push(result);
            result = 0;
        }
 
        else if (ctt == -999) {
            while (1) {
                if (top == -1)
                    return 0;
                printf("%d ", pop());
            }
        }
    }
     
 
    return 0;
}