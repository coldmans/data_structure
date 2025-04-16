#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head = 0;
 
// -----------------------------------------------
struct node * tail = 0;
 
void addToDLL(int _data){
    struct node * p = (struct node *)malloc(sizeof(struct node));
    p->data = _data;
    p->next = p->prev = 0;
     
    if(head == 0){
        head = p;
        tail = p;
        return;
    }
    else{
        p->prev =tail;
        tail->next = p;
        tail = p;
        return;
    }
}
 
void delFromDLL(int _data){
    struct node * tmp = head;
    while(1){
        if(tmp == 0) return;
        if(tmp->data == _data) break;
        tmp = tmp->next;
    }
    if(tmp->prev != 0 && tmp->next != 0){
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        free(tmp);
        return;
    }
    else if(tmp == head){
        if(tmp->next ==0){
            head = 0;
            tail = 0;
            free(tmp);
            return;
        }
        head = head->next;
        head->prev = 0;
        free(tmp);
        return;
    }
    else if(tmp->next == 0){
        tail = tail->prev;
        tail->next = 0;
        free(tmp);
        return;
    }
 
}
 
// ------------ 이하 수정금지 ---------------------
 
int main(void) {
 
    int d;
    int i;
    struct node* k = 0;
 
    while (1) {
        scanf("%d", &d);
        if (d < 0) {
            break;
        }
        addToDLL(d);
    }
 
    delFromDLL(45);
    delFromDLL(50);
    delFromDLL(60);
 
    k = head;
    for (i = 0; i < -d; i++) {
        k = k->next;
    }
    k = k->prev;
    printf("%d", k->data);
    return 0;
}