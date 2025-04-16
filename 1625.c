#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
 
#define MAX_STACK_SIZE 20
 
int stack[MAX_STACK_SIZE];
int top = -1;
 
 
 
int is_full() {
    return(top == (MAX_STACK_SIZE - 1));
}
 
int is_empty() {
    return (top == -1);
}
 
void push(int item) {
    if (is_full()) {
        return;
    }
     
    stack[++top] = item;
    return;
}
 
int pop() {
    if (is_empty())
        exit(1);
    return stack[top--];
}
 
int peek() {
    if (is_empty())
        exit(1);
    return (stack[top]);
}
 
int main(void) {
    int ctt;
    int result = 0;
     
    while (1) {
        scanf("%d", &ctt);
 
     
 
        if (ctt == -1) {
            if (!is_empty()) {
                pop();
            }
                 
        }
        else if (ctt == 0) {
            if (is_empty()) {
                printf("-999 ");
                return 0;
            }
            else {
                result = peek() + stack[0];
                printf("%d", result);
                return 0;
            }
        }
 
        else if(ctt > 0) {
            if (!(is_full())) {
                push(ctt);
            }
        }
 
    }
 
    return 0;
}