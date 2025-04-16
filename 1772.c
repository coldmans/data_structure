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
    Node* tmp = tail;
 
    while (1) {
        if (tmp == 0)
            return;
        printf("%d ", tmp->data);
        tmp = tmp->prev;
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
    print_DLL();
 
    return 0;
}