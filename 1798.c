#include <stdio.h>
#include <stdlib.h>
 
int top = -1;
int data[5];
 
void push(int v) {
    if (top != 4) data[++top] = v;
}
 
int pop() {
    if (top != -1) return data[top--];
    return 0;
}
 
int main() {
    int a;
    while (1) {
        scanf("%d", &a);
        if (a > 0) push(a);
        if (a == 0) {
            while (top != -1) printf("%d ", pop());
            break;
        }
    }
    return 0;
}