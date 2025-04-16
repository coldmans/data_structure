#define _CRT_SECURE_NO_WARNINGS
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
    while (1) {
        if (node->data < tmp->data) {
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
 
Node* small_node(Node* root) {
    if (root == 0) return 0;
    Node* tmp = root;
    while (1) {
        if (tmp->left == 0) return tmp;
        tmp = tmp->left;
    }
}
 
 
Node* delete_node(Node* root, int v) {
    if (root == 0) return 0;
    if (v < root->data)
        root->left = delete_node(root->left, v);
    else if (v > root->data)
        root->right = delete_node(root->right, v);
    else {
        if (root->left == 0) {
            Node* tmp = root->right;
            free(root);
            return tmp;
        }
        else if (root->right == 0) {
            Node* tmp = root->left;
            free(root);
            return tmp;
        }
        Node* tmp = small_node(root->right);
        root->data = tmp->data;
        root->right = delete_node(root->right, tmp->data);
    }
    return root;
}
 
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
 
void inorder_find(Node* root) {
    if (root) {
        inorder_find(root->left);
        if (root->left == 0 && root->right == 0) 
            ctt++;
        inorder_find(root->right);
    }
}
 
int main(void) {
    int c, d;
    while (1) {
        scanf("%d", &c);
        if (c > 0) add_node(c);
 
        else if (c == 0) 
        {
            while (1) 
            {
                scanf("%d", &d);
                if (d == -1) 
                {
                    inorder(root);
                    return 0;
                }
                else if (d == -2) 
                {
                    inorder_find(root);
                    printf("%d\n", ctt);
                    return 0;
                }
                else if (d > 0) 
                {
                    delete_node(root, d);
                }
 
            }
        }
    }
 
    return 0;
}