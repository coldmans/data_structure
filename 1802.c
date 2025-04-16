#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    struct Node* left, * right;
    int data;
}Node;
 
Node* root = 0;
 
Node* create_node(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->left = p->right = 0;
    p->data = v;
    return p;
}
 
void add_node(int v) {
    Node * node = create_node(v);
    if (root == 0) {
        root = node;
        return;
    }
    Node* tmp = root;
    while (1) {
        if (v < tmp->data) {
            if (tmp->left == 0) {
                tmp->left = node;
                return;
            }
            tmp = tmp->left;
        }
        else {
            if (tmp->right == 0) {
                tmp->right = node;
                return;
            }
            tmp = tmp->right;
        }
    }
}
 
void inorder(Node* p) {
    if (p) {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}
 
int main() {
    int a;
    while (1) {
        scanf("%d", &a);
        if (a > 0)
            add_node(a);
        if (a == 0) {
            if (root == 0) {
                printf("empty");
                return 0;
            }
            inorder(root);
            return 0;
        }
         
    }
    return 0;
}