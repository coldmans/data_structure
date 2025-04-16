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
    p->data = _v;
    p->next = p->prev = 0;
    return p;
}
 
Node* findNode(int _k) {
    Node* tmp = head;
    while (1) {
        if (tmp == 0)
            return tmp;
        if (tmp->data == _k)
            return tmp;
        tmp = tmp->next;
    }
    return tmp;
}
 
void front_add(int _v) {
    Node* p = createNode(_v);
    if (head == 0) {
        head = p;
        tail = p;
        return;
    }
    else {
        p->next = head;
        head->prev = p;
        head = p;
        return;
    }
}
 
 
 
 
void del_DLL(int _v) {
    if (head == 0)
        return;
     
        Node* target = findNode(_v);
        if (target == 0) {
            return;
        }
 
        if (target->next != 0 && target->prev != 0) {
            target->prev->next = target->next;
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
                return;
            }
        }
        else if (target == tail) {
            tail = target->prev;
            target->prev->next = 0;
            free(target);
        }
}
 
void hols_add(int _v) {
    Node* p = createNode(_v);
    if (head == 0) {
        head = p;
        tail = p;
        return;
    }
 
    if (head->data % 2 == 0) {
        p->next = head;
        head->prev = p;
        head = p;
        return;
    }
    Node* tmp = head;
    while (1) {
        if (tmp->data % 2 == 0)
            break;
        if (tmp->next == 0)
            break;
        tmp = tmp->next;
    }
    p->next = tmp;
    p->prev = tmp->prev;
    tmp->prev->next = p;
    tmp->prev = p;
    return;
}
 
void add_to_DLL(int _v) {
    if (_v % 2 != 0) {
        hols_add(_v);
        return;
    }
    Node* p = createNode(_v);
    Node* tmp = head;
    if (head == 0) {
        head = p;
        tail = p;
        return;
    }
    while (1) {
        if (tmp->next == 0)
            break;
        tmp = tmp->next;
    }
    p->prev = tmp;
    tmp->next = p;
    tail = p;
    return;
}
 
void insert_after(int _k, int _v) {
    Node* p = createNode(_v);
    Node* target = findNode(_k);
 
    if (target == 0)
        return;
 
    if (target->next != 0) {
        p->next = target->next;
        p->prev = target;
        target->next = p;
        p->next->prev = p;
        return;
    }
    else {
        target->next = p;
        p->prev = target;
        tail = p;
        return;
    }
 
 
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
 
 
void baprint_DLL() {
    Node* tmp = tail;
    while (1) {
        if (tmp == 0)
            return;
        printf("%d ", tmp->data);
        tmp = tmp->prev;
    }
}
 
int main(void) {
     
    int val;
    int de;
    int im;
         
    while (1) {
        scanf("%d", &im);
        if (im == 0) {
            baprint_DLL();
            return 0;
        }
        add_to_DLL(im);
    }
         
     
 
    return 0;
}