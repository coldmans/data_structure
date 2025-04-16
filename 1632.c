#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    struct Node* next;
    struct Node* prev;
    int data;
}Node;
 
Node* head = 0;
Node* tail = 0;
 
Node* create_Node(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = v;
    p->prev = p->next = 0;
    return p;
}
 
void push_DLL(int v) {
    Node* p = create_Node(v);
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
 
void pop_DLL() {
    Node* tmp = tail;
    if (tmp == 0)
        return;
    if (head == tail) {
        head = 0;
        tail = 0;
        free(tmp);
        return;
    }
    else {
        tail = tail->prev;
        tail->next = 0;
        free(tmp);
        return;
    }
}
 
void print_DLL() {
    Node* tmp = head;
    if (head == 0) {
        printf("-999");
        return;
    }
    while (1) {
        if (tmp == 0)
            return;
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}
 
void reverse_DLL() {
    Node* tmp = tail;
    while (1) {
        if (tmp == 0)
            return;
        printf("%d ", tmp->data);
        tmp = tmp->prev;
    }
}
 
int main(void) {
    int ct;
    while (1) {
        scanf("%d", &ct);
        if (ct > 0)
            push_DLL(ct);
        else if (ct == -1)
            pop_DLL();
        else if (ct == 0) {
            reverse_DLL();
            print_DLL();
             
            return 0;
        }
 
    }
 
    return 0;
}