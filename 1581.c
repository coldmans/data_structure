#include <stdio.h> 
#include <stdlib.h> 
struct node { 
    int data; 
    struct node* next;
}; 
struct node* head = 0; 
// ------------------------------------------- 
void addToSLL(int _d){
    struct node * p = (struct node *)malloc(sizeof(struct node));
    p->data = _d;
    p->next = 0;
    if(head == 0){
        head = p;
        return;
    }
    struct node * tmp = head;
    while(1){
        if(tmp->next == 0) break;
        tmp = tmp->next;
    }
    tmp->next = p;
    return;
}  
 
void insertIntoSLL(int _a, int _b){
    if(head == 0) return;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = _b;
    p->next = 0;
     
    struct node * tmp = head;
    while(1){
        if(tmp == 0) return;
        if(tmp->data == _a) break;
        tmp = tmp->next;
    }
    if(tmp->next == 0){
        tmp->next = p;
        return;
    }
    else if(tmp->next != 0){
        p->next = tmp->next;
        tmp->next = p;
        return;
    }
}  
  
 
void delFromSLL(int _d)  {
    if(head == 0) return;
    struct node * tmp = head;
    struct node * prev = 0;
    while(1){
        if(tmp == 0) return;
        if(tmp->data == _d) break;
        prev = tmp;
        tmp = tmp->next;
    }
    if(tmp->next != 0 && prev != 0){
        prev->next = tmp->next;
        free(tmp);
        return;
    }
    else if(tmp == head){
        if(tmp->next == 0){
            head = 0;
            free(tmp);
            return;
        }
        head = head->next;
        free(tmp);
        return;
    }
    else if(tmp->next == 0){
        prev->next = 0;
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
        scanf("%d", &d); if (d < 0) { break;
        }
        addToSLL(d);
    }
 
    insertIntoSLL(-d, -d*10);
    insertIntoSLL(40, -d*20);
 
    delFromSLL(-d);
    delFromSLL(-d/2);
 
    printf("%d ", head->data);
    k = head; while(k->next != 0) {
       k = k->next;
    }
    printf("%d", k->data); return 0;
}