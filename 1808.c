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
    p->data = v;
    p->left = p->right = 0;
    return p;
}
 
Node* search_node(int v) {
    Node* tmp = root;
    while (1) {
        if (tmp == 0) 
            return 0;
        if (v < tmp->data)
            tmp = tmp->left;
        else if (v > tmp->data)
            tmp = tmp->right;
        else
            return tmp;
    }
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
int left = 0;
int right = 0;
 
void inorder_left(Node* p) {
    if (p) {
        inorder_left(p->left);
        left++;
        inorder_left(p->right);
    }
}
 
void inorder_right(Node* p) {
    if (p) {
        inorder_right(p->left);
        right++;
        inorder_right(p->right);
    }
}
 
 
 
 
int main() {
    int i;
    int res = 0;
     
    while (1) {
        scanf("%d", &i);
        if (i > 0)
            add_node(i);
        else if (i < 0) {
            Node* tmp = search_node(i * -1);
            inorder_left(tmp->left);
            inorder_right(tmp->right);
            if (left - right < 0)
                res = right - left;
            else
                res = left - right;
            printf("%d", res);
            return 0;
        }
    }
    return 0;
}