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
    Node* p = (Node*)malloc(sizeof(Node));
    p->next = p->prev = 0;
    p->data = v;
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
 
void delete_DLL(int v) {
    if (head == 0)
        return;
    Node* target = find_Node(v);
    if (target == 0)
        return;
     
    if (target == head) {
        if (target->next == 0) {
            head = 0;
            tail = 0;
            free(target);
            return;
        }
        else {
            head = head->next;
            head->prev = 0;
            free(target);
            return;
        }
    }
    else if (target->next != 0 && target->prev != 0) {
        target->prev->next = target->next;
        target->next->prev = target->prev;
        free(target);
        return;
    }
    else if (target->next == 0) {
        tail = tail->prev;
        target->prev->next = 0;
        free(target);
        return;
    }
}
 
void insert_after(int k, int v) {
    if (head == 0)
        return;
     
    Node* p = create_Node(v);
    Node* target = find_Node(k);
 
    if (target == 0) 
        return;
     
 
    if (target->next == 0) {
        p->prev = target;
        target->next = p;
        tail = p;
         
    }
    else {
        p->next = target->next;
        p->prev = target;
        target->next = p;
        p->next->prev = p;
        return;
    }
}
 
void insert_before(int k, int v) {
    if (head == 0)
        return;
    Node* p = create_Node(v);
    Node* target = find_Node(k);
 
    if (target == 0)
        return;
    if (target == head) {
        p->next = target;
        target->prev = p;
        head = p;
        return;
    }
    else {
        p->next = target;
        p->prev = target->prev;
        p->prev->next = p;
        p->next->prev = p;
        return;
    }
 
}
 
void print_DLL() {
    Node* tmp = tail;
 
    if (head == 0) {
        printf("-999");
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
    int ctt = 0;
    int val= 0;
    int a, b, c,d = 0;
    while (1) {
        scanf("%d", &ctt);
 
        if (ctt > 0) {
            push_DLL(ctt);
        }
        else if (ctt == -1) {
            scanf("%d", &val);
            delete_DLL(val);
        }
        else if (ctt == -2) {
            scanf("%d",&a);
            scanf("%d",&b);
            insert_after(a, b);
        }
        else if (ctt == -3) {
            scanf("%d",&c);
            scanf("%d",&d);
            insert_before(c, d);
        }
        else if (ctt == 0) {
            print_DLL();
            return 0;
        }
    }
    return 0;
}