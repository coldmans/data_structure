#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int data;
    struct Node* next;
}Node;
 
Node* head = 0;
 
Node* create_Node(int _v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = _v;
    p->next = 0;
    return p;
}
 
void add_SLL(int _v) {
    Node* p = create_Node(_v);
    if (head == 0) {
        head = p;
        return;
    }
    Node* tmp = head;
    while (1) {
        if (tmp == 0)
            return;
        if (tmp->next == 0)
            break;
        tmp = tmp->next;
    }
    tmp->next = p;
    return;
}
 
void print_SLL() {
    Node* tmp = head;
    while (1) {
        if (tmp == 0)
            return;
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}
 
void hols_add(int _v) {
    Node* p = create_Node(_v);
    if (head == 0) {
        head = p;
        return;
    }
    if (head->data % 2 == 0) {
        p->next = head;
        head = p;
        return;
 
    }
    Node* tmp = head;
    Node* prev = 0;
    while (1) {
        if (tmp == 0)
            break;
        if (tmp->next->data % 2 == 0)
            break;
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == 0) {
        prev->next = p;
        return;
    }
    p->next = tmp->next;
    tmp->next = p;
    return;
}
 
int main(void) {
    int a;
    while (1) {
        scanf("%d", &a);
        if (a == 0) {
            print_SLL();
            return 0;
        }
 
        if (a % 2 == 0)
            add_SLL(a);
        else
        {
            hols_add(a);
        }
         
    }
 
 
}