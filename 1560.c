#include <stdio.h>
 
#define STK_SIZE 10
int my_stack[STK_SIZE];
int top = -1;
 
//-------------- 윗부분 절대 수정 금지 --------------------
void push (int v){
    if(top == 9) return;
    my_stack[++top] = v;
}
int pop(){
    if(top == -1) return -999;
    return my_stack[top--];
}
//-------------- 이하 절대 수정 금지 --------------------
 
int main(void) {
 
    int d;
     
    while (1) {
        scanf("%d", &d);
        if (d < 0) {
            break;
        }
        push(d);
    }
 
    pop();
    printf("%d ", pop());
    pop();
    printf("%d", pop());
 
    return 0;
 
}