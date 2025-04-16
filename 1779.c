#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
 
 
typedef struct Node {
    struct Node* next;
    int data;
}Node;
 
Node* head = 0;
 
Node* create_node(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = v;
    p->next = 0;
    return p;
}
 
void add_node(int v) {
    Node* p = create_node(v);
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
 
void delete_node(int v) {
    while (1) {
        Node* tmp = head;
        Node* prev = head;
         
        while (1) {
            if (tmp == 0)
                return;
            if (tmp->data == v)
                break;
            prev = tmp;
            tmp = tmp->next;
        }
        if (head == tmp) {
            if (tmp->next == 0) {
                head = 0;
                free(tmp);
                return;
            }
            head = head->next;
            free(tmp);
        }
        else if (tmp->next != 0) {
            prev->next = tmp->next;
            free(tmp);
        }
        else if (tmp->next == 0) {
            prev->next = 0;
            free(tmp);
        }
    }
}
 
void print_node() {
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
    int ctt,val;
    while (1) {
        scanf("%d", &ctt);
        if (ctt > 0)
            add_node(ctt);
        else if (ctt == 0) {
            while (1) {
                scanf("%d", &val);
                if (val == -1) {
                    print_node();
                    return 0;
                }
                else {
                    delete_node(val);
                }
            }
        }
    }
}