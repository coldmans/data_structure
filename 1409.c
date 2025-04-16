#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
}Node;
 
Node* head = 0;
Node* tail = 0;
 
Node* create_Node(int _v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = _v;
    p->prev = p->next = 0;
    return p;
}
 
void push_Node(int _v) {
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
 
void pop_Node() {
    if (head == 0) {
        return;
    }
    Node* target = tail;
    if (head == tail) {
        head = 0;
        tail = 0;
        free(target);
        return;
    }
    tail = tail->prev;
    tail->next = 0;
    free(target);
    return;
}
 
void deque_Node() {
    if (head == 0)
        return;
    Node* tmp = head;
    if (tmp->next == 0) {
        head = 0;
        tail = 0;
        return;
    }
    else {
        head = head->next;
        head->prev = 0;
        free(tmp);
        return;
    }
}
 
void print_DLL() {
    Node* tmp = head;
    if (head == 0)
        printf("Nothing");
    while (1) {
        if (tmp == 0)
            return;
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}
 
int main(void) {
 
    int val, ctt;
    while (1) {
        scanf("%d", &val);
        if (val == -1) {
            scanf("%d", &ctt);
            push_Node(ctt);
        }
        else if (val == -2) {
            scanf("%d", &ctt);
            if (ctt == -2) {
                pop_Node();
            }
        }
        else if (val == -3) {
            scanf("%d", &ctt);
            push_Node(ctt);
        }
        else if (val == -4) {
            scanf("%d", &ctt);
            if (ctt == -4) {
                deque_Node();
            }
        }
        else if (val == -999) {
            scanf("%d", &ctt);
            if (ctt == -999) {
                print_DLL();
                return 0;
            }
        }
    }
 
    return 0;
}