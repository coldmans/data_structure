#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Node {
    int data;
    struct Node* next;
}Node;
 
Node* head = 0;
 
Node* create_Node(int _v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = _v;
    p->next = 0;
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
 
void add_Node(int _v) {
    Node* p = create_Node(_v);
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
 
void delete_Node(int _v) {
    Node* tmp = head;
    Node* prev = NULL;
 
    while (tmp != NULL) {
        if (tmp->data == _v) {
            Node* target = tmp;
            if (prev == NULL) {
                head = tmp->next;
                tmp = head;
            }
            else {
                prev->next = tmp->next;
                tmp = prev->next;
            }
            free(target);
        }
        else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
}
 
void print_Node() {
    Node* tmp = head;
    if (tmp == 0) {
        printf("-999");
        return;
    }
    while (1) {
        if (tmp == 0)
            return;
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
}
 
int main(void) {
    int a, b;
    while (1) {
        scanf("%d", &a);
        if (a == 0) {
            while (1) {
                scanf("%d", &b);
                if (b == -1) {
                    print_Node();
                    return 0;
                }
                delete_Node(b);
            }
        }
        add_Node(a);
    }
 
 
    return 0;
}