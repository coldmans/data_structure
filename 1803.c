#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node {
    struct Node* left, * right;
    int data;
}Node;
 
int ctt = 0;
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
 
void count_node(Node* node) {
    if (node) {
        count_node(node->left);
        if (node->left == 0 && node->right == 0) 
            ctt++;
        count_node(node->right);
    }
}
 
int main() {
    int i;
    while (1) {
        scanf("%d", &i);
        if (i > 0)
            add_node(i);
        else if (i == 0) {
            if (root == 0) {
                printf("empty");
                return 0;
            }
            count_node(root);
            printf("%d", ctt);
            return 0;
        }
    }
    return 0;
}