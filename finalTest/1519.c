#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Node{
    struct Node *next;
    int key;
    char data[21];
}Node;
 
Node * hash[10] = {0};
 
int idx(int n){
    return n % 10;
}
 
void add(int n, char *data){
    int key = idx(n);
    Node * p = (Node *)malloc(sizeof(Node));
    strcpy(p->data, data);
    p->key = n;
    p->next = hash[key];
    hash[key] = p;
}
 
char * search(int n){
    int key = idx(n);
    int col = 0;
    Node * tmp = hash[key];
    while(1){
        if(tmp == 0) break;
        if(tmp->key == n){
            if(col || tmp->next){
                static char result[21];
                strcpy(result, "c");
                strcat(result, tmp->data);
                return result;
            }
            else{
                return tmp->data;
            }
        }
        tmp = tmp->next;
        col = 1;
    }
    return NULL;
}
 
 
int main(){
    int num;
    int data[21];   
    while(1){
        scanf("%d", &num);
        scanf("%s", data);
        if(num == -999 && (strcmp(data, "aaa") == 0)) break;
        add(num, data);
    }
    scanf("%d", &num);
    if(search(num) == NULL) printf("NULL");
    else printf("%s", search(num));
    return 0;
}
 
 
 
/**************************************************************
    Problem: 1519
    User: DA202101681
    Language: C
    Result: Accepted
    Time:1 ms
    Memory:1092 kb
****************************************************************/