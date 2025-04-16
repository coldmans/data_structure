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
 
void add_node(int v) {
    Node * p = create_node(v);
    if (root == 0) {
        root = p;
        return;
    }
    Node* tmp = root;
    while (1) {
        if (v < tmp->data) {
            if (tmp->left == 0) {
                tmp->left = p;
                return;
            }
            tmp = tmp->left;
        }
        else {
            if (tmp->right == 0) {
                tmp->right = p;
                return;
            }
            tmp = tmp->right;
        }
    }
}
 
void delete_node(int v) {
    Node* tmp = root;
    Node* p = 0;
    while (1) {
        if (tmp == 0) return;
        if (tmp->data == v) break;
        p = tmp;
        if (v < tmp->data)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
 
    if (tmp->left == 0 && tmp->right == 0) {
        if (p == 0)
            root = 0;
        else if (p->left == tmp)
            p->left = 0;
        else
            p->right = 0;
        free(tmp);
        return;
    }
    else if (tmp->left == 0 || tmp->right == 0) {
        Node* child;
        if (tmp->left != 0)
            child = tmp->left;
        else
            child = tmp->right;
         
        if (p == 0)
            root = child;
        else if (p->left == tmp)
            p->left = child;
        else
            p->right = child;
        free(tmp);
        return;
    }
    else {
        Node* succ = tmp->right;
        p = tmp;
        while (1) {
            if (succ->left == 0) break;
            p = succ;
            succ = succ->left;
        }
        tmp->data = succ->data;
        if (p->right == succ)
            p->right = succ->right;
        else
            p->left = succ->right;
    }
}
 
void delete_small() {
    Node* tmp = root;
    if (tmp == 0) return;
    while (1) {
         
        if (tmp->left == 0) {
            delete_node(tmp->data);
            return;
        }
        tmp = tmp->left;
    }
}
 
 
void delete_max() {
    Node* tmp = root;
    if (tmp == 0) return;
    while (1) {
 
        if (tmp->right == 0) {
            delete_node(tmp->data);
            return;
        }
        tmp = tmp->right;
    }
}
 
void inorder(Node* node) {
    if (node) {
        printf("%d ", node->data);
        inorder(node->left);
        inorder(node->right);
         
    }
}
 
 
int main(void) {
    int a,c;
    while (1) {
        scanf("%d", &c);
        if (c > 0) add_node(c);
        else if (c == -1) {
            scanf("%d", &a);
            delete_node(a);
        }
        else if (c == -2) {
            if(root!= 0)
                delete_node(root->data);
        }
        else if (c == -3) {
                delete_small();
        }
        else if (c == -4) {
            delete_max();
        }
        else if (c == 0) {
            if (root == 0) {
                printf("-999");
                return 0;
            }
            inorder(root);
            return 0;
        }
    }
 
    return 0;
}