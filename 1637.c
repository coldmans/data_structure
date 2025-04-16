#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    struct Node* next, * prev;
    int data;
}Node;
 
Node* head = 0;
Node* tail = 0;
 
Node* create(int v) {
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
 
void insert_before(int k, int v) {
    Node* target = findnode(k);
    Node* p = create(v);
    if (target == head) {
        target->prev = p;
        p->next = target;
        head = p;
        return;
    }
    p->next = target;
    p->prev = target->prev;
    target->prev->next = p;
    p->next->prev = p;
    return;
}
 
void add_node(int v) {
    Node* p = create(v);
    if (head == 0) {
        head = p;
        tail = p;
        return;
    }
    Node* tmp = head;
    while (1) {
        if (tmp == 0)
            break;
        if (tmp->data > v) {
            insert_before(tmp->data , v);
            return;
        }
        tmp = tmp->next;
    }
    p->prev = tail;
    tail->next = p;
    tail = p;
    return;
}
 
void deque() {
    if (head == 0)
        return;
    Node* target = head;
    if (head->next != 0) {
        head = head->next;
        head->prev = 0;
        free(target);
        return;
    }
    else {
        head = 0;
        tail = 0;
        free(target);
        return;
    }
}
 
 
void print_que() {
    Node* tmp = tail;
    if (tmp == 0) {
        printf("0");
        return;
    }
    while (1) {
        if (tmp == 0)
            return;
        printf("%d ", tmp->data);
        tmp = tmp->prev;
    }
}
 
int main(void) {
    int ctt;
    while (1) {
        scanf("%d", &ctt);
        if (ctt > 0)
            add_node(ctt);
        else if (ctt == -1)
            deque();
        else if (ctt == 0) {
            print_que();
            return 0;
        }
    }
 
    return 0;
}