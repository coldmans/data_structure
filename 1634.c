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
    p->next = p->prev = 0;
    return p;
}
 
Node* findnode(int v) {
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
    else {
        p->prev = tail;
        tail->next = p;
        tail = p;
        return;
    }
}
 
void deque() {
    if (head == 0)
        return;
    Node* tmp = head;
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
 
void swap() {
    if (head == 0)
        return;
    Node* target = head;
    Node* targets = tail;
    if (head->next == 0) {
        head = 0;
        tail = 0;
        free(target);
        return;
    }
    else {
        head = head->next;
        head->prev = 0;
        free(target);
    }
 
    if (tail->prev == 0) {
        head = 0;
        tail = 0;
        free(targets);
        return;
    }
    else {
        tail = tail->prev;
        tail->next = 0;
        free(targets);
    }
     
 
    if (head == tail)
        return;
 
    int p = 0;
    int res = 0;
    do {
        p = 0;
        Node* tmp = head;
        while (1) {
            if(tmp == 0)
                break;
            if (tmp->next == 0)
                break;
            if (tmp->data > tmp->next->data) {
                res = tmp->next->data;
                tmp->next->data = tmp->data;
                tmp->data = res;
                p = 1;
            }
            tmp = tmp->next;
        }
    } while (p);
}
 
 
void print_node() {
    if (head == 0) {
        printf("0");
        return;
    }
         
    Node* tmp = head;
     
    while (1) {
        if (tmp == 0)
            break;
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
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
            if (head != 0 && tail != 0) {
                if (head->data == tail->data) {
                    printf("-999");
                    return 0;
                }
            }
            swap();
            print_node();
            return 0;
        }
    }
 
    return 0;
}