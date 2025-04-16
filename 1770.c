#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int data;
    struct Node* next;
};
 
struct Node* head = 0;
 
void add_to_SLL(int _v) {
    struct Node *new_one = (struct Node *)malloc(sizeof(struct Node));
 
    new_one->data = _v;
    new_one->next = 0;
 
    if (head == 0) {
        head = new_one;
        return;
    }
    struct Node* tmp = head;
 
    while (1) {
        //탈출 조건
        if (tmp->next == 0) {
            break;
        }
        tmp = tmp->next;
    }
    //맨 마지막 꼬리연결
    tmp->next = new_one;
    return;
}
 
void print_SLL(void) {
    struct Node* tmp = head;
 
    if (tmp == 0) {
        return;
    }
 
    while (1) {
        if (tmp == 0)
            return;
 
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}
 
void remove_from_SLL(int _v) {
    if (head == 0) {
        return;
    }
    struct Node* tmp = head;
 
    while (1) {
        if (tmp == 0) {
            return;
        }
        if (tmp->data == _v) {
            break;
        }
        tmp = tmp->next;
    }
 
    if (tmp == head) {
        head = head->next;
        free(tmp);
        return;
    }
 
    struct Node* prev_tmp = head;
    while (1) {
        if (prev_tmp->next == tmp) {
            break;
        }
        prev_tmp = prev_tmp->next;
    }
 
    prev_tmp->next = tmp->next;
    free(tmp);
    return;
}
 
 
 
int main(void) {
 
    int a,x,rv;
    scanf("%d", &a);
 
    for (int i = 0; i < a; i++) {
        scanf("%d", &x);
        add_to_SLL(x);
    }
    scanf("%d", &rv);
    remove_from_SLL(rv);
 
 
    print_SLL();
 
 
    return 0;
}