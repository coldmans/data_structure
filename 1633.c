#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    struct Node* next;
    int data;
}Node;
 
Node* head = 0;
 
Node* create_node(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = v;
    p->next = 0;
    return p;
}
 
void enque(int v) {
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
 
void deque() {
    if (head == 0)
        return;
    Node* target = head;
    if (head->next == 0) {
        head = 0;
        free(target);
        return;
    }
    head = head->next;
    free(target);
    return;
}
 
void max() {
    if (head == 0)
        return;
    int res = head->data;
    Node* tmp = head;
    while (1) {
        if (tmp == 0)
            break;
        if (tmp->data > res)
            res = tmp->data;
 
        tmp = tmp->next;
    }
    printf("%d", res);
    return;
}
 
int main(void) {
    int ctt;
    while (1) {
        scanf("%d", &ctt);
        if (ctt > 0)
            enque(ctt);
        else if (ctt == -1)
            deque();
        else if (ctt == 0) {
            max();
            return 0;
        }
 
    }
 
 
    return 0;
}