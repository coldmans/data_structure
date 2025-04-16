#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5
 
int top = -1;
int data[MAX_STACK_SIZE];
 
void push(int v) {
    if (top == MAX_STACK_SIZE - 1)
        return;
    data[++top] = v;
}
 
int pop() {
    if (top > -1) {
        return data[top--];
    }
    exit(1);
}
 
int main() {
    int cal;
    int result = 0;
    while (1) {
        scanf("%d", &cal);
        if (cal > 0)
            push(cal);
        else if (cal == -999) {
            while (1) {
                if (top == -1)
                    return 0;
                printf("%d ", pop());
            }
        }
        else if (cal < 0) {
            while (1) {
                if (top == -1)
                    break;
                result += pop();
            }
            push(result);
            result = 0;
        }
    }
 
 
    return 0;
}