#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node{
    int key;
    struct Node * next;
}Node;
 
Node* hash[10] = {0};
 
int idx(int n){ 
    return n % 10;
}
 
void add(int n){
    int key = idx(n);
    Node * p = (Node *)malloc(sizeof(Node));
    p->key = n;
    p->next = hash[key];
    hash[key] = p;
}
 
int find_max(int k){
    int key = idx(k);
    Node * tmp = hash[key];
    int max = 0;
    while(1){
        if(tmp == 0) break;
        if(max < tmp->key){
            max = tmp->key;
        } 
        tmp = tmp->next;
    }
    return max;
}
 
int main(){
    int n;
    while(1){
        scanf("%d", &n);
        if(n == -999) break;
        add(n);
    }
    scanf("%d", &n);
    printf("%d", find_max(n));
    return 0;
}
 
/**************************************************************
    Problem: 1520
    User: DA202101681
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:1084 kb
****************************************************************/