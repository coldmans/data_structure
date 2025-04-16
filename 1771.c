#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
 
struct NODE {
    int data;
    struct NODE* next;
};
 
struct NODE* head = 0;
 
void addToSLL(int v) {
    struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->data = v;
    newNode->next = 0;
    if (head == 0) {
        head = newNode;
        return;
    }
    struct NODE* cur = head;
    while (1) {
        if (cur->next == 0) break;
        cur = cur->next;
    }
    cur->next = newNode;
    return;
}
 
void printSLL(void) {
    struct NODE* cur = head;
    if (cur == 0)return;
    while (1) {
        if (cur == 0)return;
        printf("%d ", cur->data);
        cur = cur->next;
    }
}
 
void insertSLL(int p, int v) {
    struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->data = v;
    newNode->next = 0;
    if (!p) {
        newNode->next = head;
        head = newNode;
        return;
    }
 
    struct NODE* cur = head;
    for (int i = 0; i < p - 1; i++) {
        cur = cur->next;
    }
 
    struct NODE* next_cur = cur->next;
    newNode->next = next_cur;
    cur->next = newNode;
    return;
}
 
int main(void) {
    int num = 0, a = 0, w1 = 0, w2 = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &a);
        addToSLL(a);
    }
    scanf("%d %d", &w1, &w2);
    insertSLL(w1, w2);
    printSLL();
    return 0;
}