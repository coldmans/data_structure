#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    struct Node* prev, * next;
    int data;
}Node;
 
Node* head = 0;
Node* tail = 0;
 
Node* create_node(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = v;
    p->prev = p->next = 0;
    return p;
}
 
Node* find_node(int v) {
    Node* tmp = head;
    while (1) {
        if (tmp == 0) return 0;
        if (tmp->data == v) return tmp;
        tmp = tmp->next;
    }
}
 
void add_node(int v) {
    Node* p = create_node(v);
    if (head == 0) {
        head = p;
        tail = p;
        return;
    }
    p->prev = tail;
    tail->next = p;
    tail = p;
}
 
void delete_node(int v) {
    while (1) {
        Node* tar = find_node(v);
        if (head == 0 || tar == 0) return;
        if (tar->prev != 0 && tar->next != 0) {
            tar->prev->next = tar->next;
            tar->next->prev = tar->prev;
            free(tar);
        }
        else if (tar == head) {
            if (tar->next == 0) {
                head = 0;
                tail = 0;
                free(tar);
            }
            else {
                head = head->next;
                head->prev = 0;
                free(tar);
            }
        }
        else if (tar == tail) {
            tail = tail->prev;
            tail->next = 0;
            free(tar);
        }
    }
}
 
void print_node() {
    Node* tmp = head;
    if (head == 0)
        printf("empty");
    while (1) {
        if (tmp == 0) return;
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}
 
int main() {
    int i;
    while (1) {
        scanf("%d", &i);
        if (i > 0)
            add_node(i);
        else if (i < 0)
            delete_node(i * -1);
        else {
            print_node();
            return 0;
        }
    }
    return 0;
}