#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* root = 0;
 
 
void addToBST(int _data) {
    struct node* nod = (struct node*)malloc(sizeof(struct node));
    nod->data = _data;
    nod->left = nod->right = 0;
    if (root == 0) {
        root = nod;
        return;
    }
 
     
    struct node* tmp = root;
 
    while (1) {
        if (nod->data < tmp->data) {
            if (tmp->left == 0) {
                tmp->left = nod;
                return;
            }
            tmp = tmp->left;
        }
        else {
            if (tmp->right == 0) {
                tmp->right = nod;
                return;
            }
            tmp = tmp->right;
        }
    }
}
 
     
//-----------------------------------------------
 
// 아래로는 수정하지 마시오
 
int main(void) {
 
    int d = 0;
    int i;
 
    for (i = 0; i < 5; i++) {
        scanf("%d", &d);
        addToBST(d);
    }
 
    printf("%d", root->left->right->data);
 
    return 0;
}