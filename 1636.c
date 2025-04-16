#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    struct Node* next, * prev;
    int data;
}Node;
 
Node* head = 0;
Node* tail = 0;
 
Node* create_node(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = v;
    p->prev = p->next = 0;
    return p;
}
 
Node* find_node(int v) {
    Node* tmp = head;
    while (1) {
        if (tmp == 0)
            return 0;
        if (tmp->data == v)
            return tmp;
        tmp = tmp->next;
    }
}
 
void enque(int v) {
    Node* p = create_node(v);
    if (head == 0) {
        head = p;
        tail = p;
        return;
    }
    Node* target = find_node(v);
    if (target == 0) {
        p->prev = tail;
        tail->next = p;
        tail = p;
        return;
    }
    else {
        if (target->prev == 0) {
            p->next = target;
            target->prev = p;
            head = p;
        }
        else {
            p->next = target;
            p->prev = target->prev;
            target->prev->next = p;
            p->next->prev = p;
        }
        Node* tp = create_node(v);
        tp->prev = tail;
        tail->next = tp;
        tail = tp;
        return;
    }
}
 
void deque() {
    Node* tmp = head;
    if (head == 0)
        return;
    if (head->next == 0) {
        head = 0;
        tail = 0;
        free(tmp);
        return;
    }
    else {
        head = head->next;
        head->prev = 0;
        free(tmp);
        return;
    }
}
 
void print_node() {
    Node* tmp = head;
    if (head == 0) {
        printf("0");
        return;
    }
    while (1) {
        if (tmp == 0)
            return;
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
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
            print_node();
            return 0;
        }
    }
 
 
    return 0;
}