#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Node{
    struct Node *next;
    int key;
    char data[20];
}Node;
 
Node *hash[10] = {0};
 
int idx(int n){
    return n % 10;
}   
 
void add(int n, char *data){
    int key = idx(n);
    Node * p = (Node *)malloc(sizeof(Node));
    p->key = n;
    strcpy(p->data,data);
    p->next = hash[key];
    hash[key] = p;
}
 
void hasing(int n){
    int key = idx(n);
    Node *p = hash[key];
    int col = 0;
    while(1){
        if(!p) return;
        if(p->key == n){
            if(col || p->next !=0){
                char data[20];
                strcpy(data, "c");
                strcat(data, p->data);
                printf("%s",data);
                return;
            }
            else{
                printf("%s",p->data);
                return;
            }
            }
            col = 1;
            p = p->next;
         
    }
}
 
int main(){
    char data[20];
    int a;
    while(1){
        scanf("%d",&a);
        scanf("%s",data);
        if(a == -999 && strcmp(data, "aaa") == 0) break;
        add(a, data);
    }
    scanf("%d",&a);
    hasing(a);
     
    return 0;
}
/**************************************************************
    Problem: 1466
    User: DA202101681
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:1092 kb
****************************************************************/