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
 
Node* create_Node(int v) {
    Node* p = (Node*)malloc(sizeof(v));
    p->data = v;
    p->next = p->prev = 0;
    return p;
}
 
Node* find_Node(int v) {
    Node* tmp = head;
    while (1) {
        if (tmp == 0)
            break;
        if (tmp->data == v)
            return tmp;
        tmp = tmp->next;
    }
    return tmp;
}
 
void add_end_Node(int v) {
    Node* p = create_Node(v);
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
 
void add_first_Node(int v) {
    Node* p = create_Node(v);
    if (head == 0) {
        head = p;
        tail = p;
        return;
    }
 
    p->next = head;
    head->prev = p;
    head = p;
    return;
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
 
int main(void) {
 
    int ctt;
    int change = 0;
    while (1) {
        scanf("%d", &ctt);
        if (ctt == -999) {
            print_DLL();
            return 0;
        }
        else if (ctt > 0) {
            if (change == 0) {
                add_end_Node(ctt);
            }
            else if (change == 1) {
                add_first_Node(ctt);
            }
        }
 
        else if (ctt == 0) {
            if (change == 0) {
                change = 1;
            }
            else {
                change = 0;
            }
        }
    }
 
 
    return 0;
}