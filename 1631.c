#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    struct Node * next;
    int data;
}Node;
 
Node* head = 0;
 
Node* create_node(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = v;
    p->next = 0;
    return p;
}
 
void push(int v) {
    Node* p = create_node(v);
    if (head == 0) {
        head = p;
        return;
    }
    Node* tmp = head;
    while (1) {
        if (tmp->next == 0)
            break;
        tmp = tmp->next;
    }
    tmp->next = p;
    return;
}
 
void pop() {
    if (head == 0)
        return;
    Node* tmp = head;
    if (head->next == 0) {
        head = 0;
        free(tmp);
        return;
    }
    Node* prev = head;
    while (1) {
        if (tmp->next == 0)
            break;
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = 0;
    free(tmp);
    return;
}
 
void print_stack() {
    int result = 0;
    if (head == 0) {
        printf("0");
        return;
    }
    Node* tmp = head;
    while (1) {
        if (tmp == 0)
            break;
        result += tmp->data;
        tmp = tmp->next;
    }
    printf("%d", result);
    return;
}
 
int main(void) {
    int ctt;
    while (1) {
        scanf("%d", &ctt);
        if (ctt > 0)
            push(ctt);
        else if (ctt == -1)
            pop();
        else if (ctt == 0) {
            print_stack();
            return 0;
        }
    }
    return 0;
}