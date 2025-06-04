#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node{
    int data;
    struct Node * left, *right;
}Node;
 
Node * root = 0;
 
Node * createNode(int v){
    Node * p = (Node *)malloc(sizeof(Node));
    p->data = v;
    p->left = p->right = 0;
    return p;
}
 
void addToBST(int v){
    Node * p = createNode(v);
    Node * tmp = root;
    if(!root){
        root = p;
        return;
    }
    while(1){
        if(v < tmp->data){
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
 
void delFromBST(int v){
    Node * p = 0;
    Node * tmp = root;
    while(1){
        if(tmp == 0) return;
        if(tmp->data == v) break;
        p = tmp;
        if(v < tmp->data) tmp = tmp->left;
        else tmp = tmp->right;
    }
     
    if(tmp->left == 0 && tmp->right == 0){
        if(!p) root = 0;
        else if(p->left == tmp) p->left = 0;
        else p->right = 0;
        free(tmp);
    }
    else if(tmp->left == 0 || tmp->right == 0){
        Node * child = 0;
        if(tmp->left != 0) child = tmp->left;
        else child = tmp->right;
        if(!p) root = child;
        else if(p->left == tmp) p->left = child;
        else p->right = child;
        free(tmp);
    }
    else{
        Node * succ = tmp->right;
        p = tmp;
        while(1){
            if(succ->left == 0) break;
            p = succ;
            succ = succ->left;
        }
        tmp->data = succ->data;
        if(p->left == succ) p->left = succ->right;
        else p->right = succ->right;
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
    Problem: 1842
    User: DA202101681
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:1084 kb
****************************************************************/