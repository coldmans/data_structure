#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define NV 30
 
typedef struct Node {
    struct Node* left, * right;
    char data[NV];
    int len;
    int ctt;
}Node;
 
Node* root = 0;
 
Node* create_node(char* mes) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->left = p->right = 0;
    p->len = strlen(mes);
    strcpy(p->data, mes);
    p->ctt = 1;
    return p;
}
 
void add_node(char* mes) {
    Node* p = create_node(mes);
    Node* tmp = root;
    if (root == 0) {
        root = p;
        return;
    }
    while (1) {
        if (strcmp(mes, tmp->data) < 0) {
            if (tmp->left == 0) {
                tmp->left = p;
                return;
            }
            tmp = tmp->left;
        } else if (strcmp(mes, tmp->data) == 0) {
            tmp->ctt++;
            return;
        } else {
            if (tmp->right == 0) {
                tmp->right = p;
                return;
            }
            tmp = tmp->right;
        }
    }
}
 
Node* find_node(Node* root, int v) {
    if (root) {
        if (root->len == v) return root;
        Node* find = find_node(root->left, v);
        if (find) return find;
        return find_node(root->right, v);
    }
    return 0;
}
 
Node* findMax() {
    Node* tmp = root;
    while (tmp && tmp->right) {
        tmp = tmp->right;
    }
    return tmp;
}
 
void inorders(Node* node) {
    if (node) {
        inorders(node->left);
        for (int i = 0; i < node->ctt; i++) {
            printf("%s ", node->data);
        }
        inorders(node->right);
    }
}
 
Node* deleteNode(Node* root, char* key) {
    if (!root) return root;
 
    if (strcmp(key, root->data) < 0)
        root->left = deleteNode(root->left, key);
    else if (strcmp(key, root->data) > 0)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
 
        Node* temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;
 
        strcpy(root->data, temp->data);
        root->len = temp->len;
        root->ctt = temp->ctt;
 
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
 
void delete_nodes_with_length(int v) {
    Node* toDelete;
    while ((toDelete = find_node(root, v)) != NULL) {
        root = deleteNode(root, toDelete->data);
    }
}
 
int main(void) {
    char data[NV];
    while (1) {
        scanf("%s", data);
        if (strcmp(data, "ab") == 0) {
            scanf("%s", data);
            int v = strlen(data);
            delete_nodes_with_length(v);
            if (root == 0) {
                printf("none");
                return 0;
            }
            inorders(root);
            return 0;
        } else {
            add_node(data);
        }
    }
    return 0;
}