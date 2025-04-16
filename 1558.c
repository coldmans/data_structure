#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node* next;
};
struct node* head = 0;
 
// -----------------------------------------------
 
 
void addToSLL(int _data){
    struct node * p = (struct node *)malloc(sizeof(struct node));
    p->data = _data;
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
        addToSLL(d);
    }
 
    k = head;
    for (i = 0; i < -d; i++) {
        k = k->next;
    }
    printf("%d", k->data);
    return 0;
}