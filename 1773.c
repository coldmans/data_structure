#include <stdio.h>
#include <stdlib.h>
  
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
  
void add_SLL(int _v) {
    Node* p = create_Node(_v);
    if (head == 0) {
        head = p;
        return;
    }
    Node* tmp = head;
    while (1) {
        if (tmp == 0)
            return;
        if (tmp->next == 0)
            break;
        tmp = tmp->next;
    }
    tmp->next = p;
    return;
}
  
void print_SLL() {
    Node* tmp = head;
    if (tmp == 0)
        printf("-999");
    while (1) {
        if (tmp == 0)
            return;
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}
  
void delete_SLL(int _v) {
    Node* tmp = head;
    Node* prev = 0;
    while (tmp != 0) {
        if (tmp->data == _v) {
            Node* to_delete = tmp;
            if (tmp == head) {
                head = tmp->next;
                tmp = head;
            } else {
                prev->next = tmp->next;
                tmp = tmp->next;
            }
            free(to_delete);
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
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
                    print_SLL();
                    return 0;
                }
                delete_SLL(b);
            }
        }
        add_SLL(a);
    }
    return 0;
}