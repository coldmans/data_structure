#include <stdio.h>
#include <stdlib.h>
 
#define _CRT_SECURE_NO_WARNINGS
 
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
 
Node* head = 0;
Node* tail = 0;
 
Node* create_Node(int _v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = _v;
    p->next = p->prev = 0;
    return p;
}
 
Node* find_Node(int _v) {
    Node* tmp = head;
    while (1) {
        if (tmp == 0)
            break;
        if (tmp->data == _v)
            return tmp;
        tmp = tmp->next;
    }
    return tmp;
}
 
void add_to_DLL(int _v) {
    Node* p = create_Node(_v);
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
 
    tmp->next = p;
    p->prev = tmp;
    tail = p;
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
 
void print_rev_DLL() {
    Node* tmp = tail;
    if(tmp == 0)
        printf("-999");
    while (1) {
        if (tmp == 0)
            return;
 
        printf("%d ", tmp->data);
        tmp = tmp->prev;
    }
}
 
void insert_after_DLL(int _k, int _v) {
    if (head == 0)
        return;
    Node* p = create_Node(_v);
    Node* target = find_Node(_k);
 
 
    if (target->next == 0) {
        target->next = p;
        p->prev = target;
        tail = p;
        return;
    }
    else {
        p->next = target->next;
        p->prev = target;
        target->next = p;
        p->next->prev = p;
        return;
    }
}
 
void del_DLL(int _k) {
    while(1){
        if (head == 0)
            return;
        Node* target = find_Node(_k);
        if (target == 0)
            return;
 
        if (target->prev != 0 && target->next != 0) {
            target->prev = target->next;
            target->next->prev = target->prev;
            free(target);
             
        }
        else if (target == head) {
            if (target->next == 0) {
                head = 0;
                tail = 0;
                free(target);
                 
            }
            else {
                head = head->next;
                head->prev = 0;
                free(target);
               
            }
        }
        else if (target->next == 0) {
   
            target->prev->next = 0;
            tail = target->prev;
            free(target);
       
        }
    }
 
}
 
int main(void) {
    int x;
    int wax;
    while (1) {
        scanf("%d", &x);
        if (x == 0) {
            while (1) {
                scanf("%d", &wax);
                if (wax == -1) {
                        print_rev_DLL();
                        return 0;
                    }
                 
                del_DLL(wax);
            }
        }
        else // DLL에 존재하지 않는 값인 경우 추가
            add_to_DLL(x);
        }
    }