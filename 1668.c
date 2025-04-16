#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int data;
    struct Node* next;
}Node;
 
Node* head = 0;
 
Node* createNode(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->next = 0;
    p->data = v;
    return p;
}
 
void push_SLL(int v) {
    Node* p = createNode(v);
    if (head == 0) {
        head = p;
        return;
    }
 
    Node* tmp = head;
    while (1) {
        if (tmp->next == 0)
            break;
        tmp = tmp->next;
    }
    tmp->next = p;
    return;
}
 
void delete_SLL(int _v) {
    Node* tmp = head;
    Node* prev = head;
    if (head == 0)
        return;
    if (tmp->data == _v) {
        head = head->next;
        free(tmp);
        return;
    }
 
    while (1) {
        if (tmp == 0)
            return;
        if (tmp->data == _v)
            break;
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp->next == 0) {
        prev->next = 0;
        free(tmp);
        return;
    }
    prev->next = tmp->next;
    free(tmp);
    return;
}
 
void insert_after(int k, int v) {
    Node* tmp = head;
    Node* p = createNode(v);
    while (1) {
        if (tmp == 0)
            return;
        if (tmp->data == k)
            break;
        tmp = tmp->next;
    }
    if (tmp->next == 0) {
        tmp->next = p;
        return;
    }
    else {
        p->next = tmp->next;
        tmp->next = p;
        return;
    }
}
 
void insert_before(int k, int v) {
    Node* tmp = head;
    Node* prev = head;
    Node* p = createNode(v);
    if (tmp == 0)
        return;
 
    if (tmp->data == k) {
        p->next = tmp;
        head = p;
        return;
    }
 
    while (1) {
        if (tmp == 0)
            return;
        if (tmp->data == k)
            break;
        prev = tmp;
        tmp = tmp->next;
    }
    p->next = tmp;
    prev->next = p;
    return;
}
 
void print_SLL() {
    Node* tmp = head;
    if (tmp == 0) {
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
 
int main(void) {
    int ctt;
    int val;
    int vals;
    while (1) {
        scanf("%d", &ctt);
 
        if (ctt > 0)
            push_SLL(ctt);
        else if (ctt == -1) {
            scanf("%d", &val);
            delete_SLL(val);
        }
        else if (ctt == -2) {
            scanf("%d %d", &val, &vals);
            insert_after(val, vals);
        }
        else if (ctt == -3) {
            scanf("%d %d", &val, &vals);
            insert_before(val, vals);
        }
        else if (ctt == 0) {
            print_SLL();
            return 0;
        }
    }
 
    return 0;
}