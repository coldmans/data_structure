#include <stdio.h>
#include <stdlib.h>
 
 
typedef struct Node{
    struct Node * next, *prev;
    int data;
    }Node;
 
Node * head = 0;
Node * tail = 0;
 
Node * find_node(int v){
    Node * tmp = head;
    while(1){
    if(tmp == 0) return 0;
    if(tmp->data == v) return tmp;
    tmp = tmp->next;
    }
}
 
Node * create_node(int v){
    Node * p = (Node *)malloc(sizeof(Node));
    p->data = v;
    p->next = p->prev = 0;
    return p;
}
 
void add_node(int v){
    Node * p = create_node(v);
    if(head == 0){
        head = p;
        tail = p;
        return;
    }
    p->prev = tail;
    tail->next = p;
    tail = p;
    return;
}
 
void delete_node(int v){
 
while(1){
    if(head == 0) return;
    Node * target = find_node(v);
    if(target == 0) return;
    if(target->next != 0 && target->prev != 0){
        target->prev->next = target->next;
        target->next->prev = target->prev;
        free(target);
    }
    else if(target == head){
        if(target->next == 0){
            head = 0;
            tail = 0;
            free(target);
        }
        else{
        head = head->next;
        head->prev = 0;
        free(target);
        }
    }
    else if(target->next == 0){
        tail = tail->prev;
        tail->next = 0;
        free(target);
    }
}
 
}
 
void print_node(){
    Node * tmp = tail;
    if(tmp == 0){
        printf("-999");
        return;
    }
    while(1){
        if(tmp == 0) return;
        printf("%d ",tmp->data);
        tmp = tmp->prev;
    }
}
 
int main(void){
    int c,d;
     
    while(1){
        scanf("%d",&c);
        if(c > 0) add_node(c);
         
        else if(c == 0){
            while(1){
                scanf("%d",&d);
                 
                if(d == -1){
                    print_node();
                    return 0;
                }
                delete_node(d);
             
            }
        }
     
     
    }
 
 
 
    return 0;
}