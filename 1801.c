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
    p->next = p->prev = 0;
    p->data = v;
    return p;
}
 
void add_node(int v) {
    Node* p = create_node(v);
    if (head == 0) {
        head = p;
        tail = p;
        return;
    }
    p->prev = tail;
    tail->next = p;
    tail = p;
    return;
}
 
void print_node() {
    Node* tmp = head;
    if (head == 0) {
        printf("empty");
        return;
    }
    while (1) {
        if (tmp == 0) return;
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}
 
void reverse_node() {
    Node* tmp = tail;
    if (tail == 0) {
        printf("empty");
        return;
    }
    while (1) {
        if (tmp == 0) return;
        printf("%d ", tmp->data);
        tmp = tmp->prev;
    }
}
 
int main() {
    int a;
    while (1) {
        scanf("%d", &a);
        if (a > 0)
            add_node(a);
        if (a == 0) {
            print_node();
            return 0;
        }
        if (a == -1) {
            reverse_node();
            return 0;
        }
    }
    return 0;
}