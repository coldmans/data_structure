#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    struct Node* left, * right;
    int data;
}Node;
 
int min, max = 0;
 
Node* root = 0;
 
Node* create_node(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = v;
    p->left = p->right = 0;
    return p;
}
 
void add_node(int v) {
    Node* node = create_node(v);
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
        if (max < p->data)
            max = p->data;
        if (min > p->data)
            min = p->data;
        inorder(p->right);
    }
}
 
 
 
 
int main() {
    int i;
     
    while (1) {
        scanf("%d", &i);
        if (i > 0)
            add_node(i);
        else if (i == 0) {
            min = root->data;
            max = root->data;
            inorder(root);
            printf("%d", max - min);
            return 0;
        }
    }
    return 0;
}