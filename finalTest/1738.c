#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node *left;
    struct node *right;
};
 
struct node *root = 0;
 
 
void addToBST(int _data){
    struct node * p = (struct node *)malloc(sizeof(struct node));
    p->data = _data;
    p->left = p->right = 0;
    if(!root){
        root = p;
        return;
    }
    struct node *tmp =root;
    while(1){
        if(_data < tmp->data){
            if(tmp->left == 0){
                tmp->left = p;
                return;
            }
            tmp = tmp->left;
        }
        else{
            if(tmp->right == 0){
                tmp->right = p;
                return;
            }
            tmp = tmp->right;
        }
    }
}
     
     
void delFromBST(int _data){
    struct node * p = 0;
    struct node * tmp = root;
    if(!root) return;
    while(1){
        if(!tmp) return; 
        if(tmp->data == _data) break;
        p = tmp;
        if(_data < tmp->data) tmp = tmp->left;
        else tmp = tmp->right;
    }
    if(tmp->left == 0 && tmp->right == 0){
        if(!p) root = 0;
        else if(p->left = tmp) p->left = 0;
        else p->right = 0;
        free(tmp);
    }
    else if(tmp->left == 0 || tmp->right ==0){
        struct node * child;
        if(tmp->left != 0) child = tmp->left;
        else child = tmp->right;
        if(!p) root = child;
        else if(p->left) p->left = child;
        else p->right = child;
        free(tmp);
    }
    else{
        struct node * succ = tmp->right;
        p = tmp;
        while(1){
            if(succ->left == 0) break;
            p = succ;
            succ = succ->left;
        }
        tmp->data = succ->data;
        if(p->right == succ) p->right = succ->right;
        else p->left = succ->right;
        free(succ);
    }
 
}
 
int main(void) {
 
    int d = 0;
    int i;
     
    for (i = 0; i < 6; i++) {
        scanf("%d", &d);
        addToBST(d);
    }
    scanf("%d", &d);
    delFromBST(d);
     
    scanf("%d", &d);
    delFromBST(d);
     
    printf("%d", root->right->data);
 
    return 0;
}
/**************************************************************
    Problem: 1738
    User: DA202101681
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:1084 kb
****************************************************************/