#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5
 
int data[MAX_STACK_SIZE];
int stack[MAX_STACK_SIZE];
int tops = -1;
int top = -1;
 
int is_full() {
    return top == MAX_STACK_SIZE - 1;
}
 
int is_empty() {
    return top == -1;
}
 
void push(int v) {
    if (is_full())
        return;
    data[++top] = v;
}
void pushes(int v) {
    if (tops == MAX_STACK_SIZE -1)
        return;
    stack[++tops] = v;
}
 
int pop() {
    if (is_empty())
        exit(1);
    return data[top--];
}
 
int pops() {
    if (tops == -1)
        exit(1);
    return stack[tops--];
}
 
 
int main(void) {
    int count;
     
    while (1) {
        scanf("%d", &count);
        if (count == -1 && top != -1)
            pop();
 
        else if (count == 0) {
 
            if (top == -1) {
                printf("-999");
                return 0;
            }
            while (1) {
                if(top == -1) {
                    break;
                }
                pushes(pop());
            }
            while (1) {
                if (tops == -1)
                    break;
                printf("%d ", pops());
            }
            return 0;
        }
        if (count > 0 && top != MAX_STACK_SIZE - 1)
            push(count);
         
             
    }
 
    return 0;
}