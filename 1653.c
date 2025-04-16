#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Node {
    struct Node* left, * right;
    char data[10];
}Node;
 
Node* root = 0;
 
Node* create_node(char * v) {
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->data, v);
    p->left = p->right = 0;
    return p;
}
 
void add_node(char * v) {
    Node* node = create_node(v);
    if (root == 0) {
        root = node;
        return;
    }
    Node* tmp = root;
    while (1) {
        if (strcmp(node->data, tmp->data) < 0) {
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
 
int main(void) {
    char ctt[10];
    int res;
    while (1) {
        scanf("%s", ctt);
        if (strcmp(ctt, "end") == 0) {
            while (1) {
                scanf("%d", &res);
                if (res == 0) {
                    if (root->left == 0) {
                        printf("INVALID");
                        return 0;
                    }
                    root = root->left;
                }
                else if (res == 1) {
                    if (root->right == 0) {
                        printf("INVALID");
                        return 0;
                    }
                    root = root->right;
                }
                else if (res == -1) {
                    printf("%s", root->data);
                    return 0;
                }
            }
        }
        else {
            add_node(ctt);
        }
    }
    return 0;
}