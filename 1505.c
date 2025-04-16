#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    int data;
    struct Node *next;
}Node;
 
Node* head = 0;
 
 
Node* create_Node(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = v;
    p->next = 0;
    return p;
}
 
void add_zzak_SLL(int v) {
    Node* p = create_Node(v);
     
    if (head == 0) {
        head = p;
        return;
    }
 
    Node* tmp = head;
 
    while(1) {
        if (tmp->next == 0)
            break;
        tmp = tmp->next;
    }
    tmp->next = p;
    return;
}
 
void add_hol_SLL(int v) {
    Node* p = create_Node(v);
    if (head == 0) {
        head = p;
        return;
    }
    else {
        p->next = head;
        head = p;
        return;
    }
}
 
void print_SLL() {
    if (head == 0) {
        return;
    }
    Node* tmp = head;
    while (1) {
        if (tmp == 0)
            break;
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}
 
int main(void) {
 
    int val;
    while (1) {
        scanf("%d", &val);
        if (val % 2 == 0)
            add_zzak_SLL(val);
        else if (val % 2 == 1)
            add_hol_SLL(val);
        else if (val == -999) {
            print_SLL();
            return 0;
        }
 
    }
    return 0;
}