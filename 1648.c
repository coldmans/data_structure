#include <stdio.h>
#include <stdlib.h>
#define MS 5
 
int top = -1;
int data[MS];
 
void push(int v){
    if(top == 4) return;
    data[++top] =v;
}
int pop(){
    if(top == -1) return 0;
    return data[top--];
}
void change(){
    int tmp = 0;
    while(1){
        if(tmp >= top) break;
         data[tmp] = data[tmp + 1];
         tmp++;
    }
    top = top -1;
}
int main(void){
    int ctt;
    while(1){
        scanf("%d", &ctt);
        if(ctt > 0){
            if(top == 4){
                change();
                push(ctt);
            }
            else{
                push(ctt);
            }
        }
        else if(ctt == 0){
            if(top == -1){
                printf("-999");
                return 0;
            }
            printf("%d",pop());
            return 0;
        }
        else if(ctt == -1){
            pop();
        }
         
    }
 
 
    return 0;
}