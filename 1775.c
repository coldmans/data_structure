#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
 
Node* head = 0;
Node* tail = 0;
 
Node* create_Node(int _v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = _v;
    p->next = p->prev = 0;
    return p;
}
 
Node* find_Node(int _k) {
    Node* tmp = head;
    while (1) {
        if (tmp == 0)
            break;
        if (tmp->data == _k)
            return tmp;
        tmp = tmp->next;
    }
    return tmp;
}
 
void add_DLL(int _v) {
    Node* p = create_Node(_v);
    if (head == 0) {
        head = p;
        tail = p;
        return;
    }
    else {
        p->prev = tail;
        tail->next = p;
        tail = p;
        return;
    }
}
 
void print_DLL() {
    Node* tmp = head;
    while (1) {
        if (tmp == 0)
            return;
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}
 
void insert_after(int _k, int _v) {
    Node* target = find_Node(_k);
    Node* p = create_Node(_v);
    if (target == 0)
        return;
    // 뒤에 차있음
    if (target->next != 0) {
        p->next = target->next;
        p->prev = target;
        target->next = p;
        p->next->prev = p;
    }
    // 뒤에 비어있음
    else {
        p->prev = target;
        target->next = p;
        tail = p;
    }
}
 
int main(void) {
    int ctt, val;
    int a, b;
    scanf("%d", &ctt);
    for (int i = 0; i < ctt; i++) {
        scanf("%d", &val);
        add_DLL(val);
    }
    scanf("%d %d", &a, &b);
    insert_after(a, b);
    print_DLL();
 
    return 0;
}