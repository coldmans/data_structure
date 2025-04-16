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
 
Node* createNode(int _v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->next = p->prev = 0;
    p->data = _v;
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
    return 0;
}
 
void push_Stack(int _v) {
    Node* p = createNode(_v);
    if (head == 0) {
        head = p;
        tail = p;
        return;
    }
    else {
        tail->next = p;
        p->prev = tail;
        tail = p;
        return;
    }
}
 
void delete_Stack(int _v) {
    if (head == 0)
        return;
 
    Node* target = find_Node(_v);
     
    if (target == 0)
        return;
 
 
    if (target->next != 0 && target->prev != 0) {
        target->prev = target->next;
        target->next->prev = target->prev;
        free(target);
    }
    else if (target == head) {
        if (target->next != 0) {
            head = head->next;
            head->prev = 0;
            free(target);
        }
        else {
            head = 0;
            tail = 0;
            free(target);
        }
    }
    else if (target->next != 0) {
        tail = target->prev;
        target->prev->next = 0;
        free(target);
    }
}
void delete_tail() {
    if (head == 0)
        return;
 
    Node* target = tail;
    if (target == 0)
        return;
    else {
        tail = tail->prev;
        target->prev->next = 0;
        free(target);
        return;
    }
}
 
void reverse_print() {
    Node* tmp = tail;
    while (1) {
        if (tmp == 0)
            return;
        printf("%d ", tmp->data);
        tmp = tmp->prev;
    }
}
 
int main(void) {
 
    int v;
    while (1) {
        scanf("%d", &v);
 
        if (v == -1) {
            delete_tail();
        }
        else if (v == 0) {
            reverse_print();
            return 0;
        }
        else {
            delete_Stack(v);
            push_Stack(v);
        }
    }
 
 
 
    return 0;
}