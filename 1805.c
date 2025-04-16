#include <stdio.h>
 
int data[5];
int top = -1;
 
void push(int v) {
    if (top != 4)
        data[++top] = v;
}
 
int pop() {
    if (top != -1)
        return data[top--];
}
 
void delete_stack() {
    for (int x = 0; x < top; x++)
        data[x] = data[x + 1];
    top--;
}
 
int main() {
    int x;
    while (1) {
        scanf("%d", &x);
         
        if (x >= 100) {
            delete_stack();
            push(x);
        }
        else if (x > 0)
            push(x);
        else if (x == 0) {
            if (top == -1)
                printf("empty");
            while (1) {
                if (top == -1)
                    return 0;
                printf("%d ", pop());
            }
        }
    }
    return 0;
}