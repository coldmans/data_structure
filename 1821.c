#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* root = 0;
 
void addToBST(int _data) {
    struct node* nodes = (struct node*)malloc(sizeof(struct node));
    nodes->data = _data;
    nodes->left= nodes->right = 0;
    if (root == 0) {
        root = nodes;
        return;
    }
    struct node* temp = root;
    while (1) {
        if (temp->data > _data) {
            if (temp->left == 0) {
                temp->left = nodes;
                return;
            }
            temp = temp->left;
        }
        else {
            if (temp->right == 0) {
                temp->right = nodes;
                return;
            }
            temp = temp->right;
        }
    }
}
 
 
void delFromBST(int _data) {
    struct node* temp = root;
    struct node* p = 0;
     
    while (temp != 0 && temp->data != _data) {
        p = temp;
        if (temp->data > _data) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    if (temp == 0) {
        return;
    }
    if (temp->left == 0 && temp->right == 0) {
        if (p == 0) {
            root = 0;
        }
        else if (p->left == temp) {
            p->left = 0;
        }
        else {
            p->right = 0;
        }
        free(temp);
    }
    else if (temp->left == 0 || temp->right == 0) {
        struct node* child = temp->left != 0 ? temp->left : temp->right;
        if (p == 0) {
            root = child;
        }
        else if (p->left == temp) {
            p->left = child;
        }
        else {
            p->right = child;
        }
        free(temp);
    }
    else {
        struct node* succ = temp->right;
        p = temp;
        while (succ->left != 0) {
            p = succ;
            succ = succ->left;
        }
        temp->data = succ->data;
        if (p->left == succ) {
            p->left = succ->right;
        }
        else {
            p->right = succ->right;
        }
        free(succ);
    }
 
}
 
int findMax(struct node* temp) {
    while (temp->right != 0) {
        temp = temp->right;
    }
    return temp->data;
}
 
int findMin(struct node* temp) {
    while (temp->left != 0) {
        temp = temp->left;
    }
    return temp->data;
}
 
void inorder(struct node* d) {
    if (d) {
        inorder(d->left);
        printf("%d ", d->data);
        inorder(d->right);
    }
}
 
 
 
int main(void) {
 
    int d;
    int i;
    int tmp;
 
    while (1) {
        scanf("%d", &i);
        if (i == -1) {
            scanf("%d", &d);
            delFromBST(d);
        }
        else if (i == -2) {
            if (root != 0) {
                delFromBST(root->data);
            }
        }
        else if (i == -3) {
            if (root != 0) {
                tmp = findMax(root);
                delFromBST(tmp);
            }
        }
        else if (i == -4) {
            if (root != 0) {
                tmp = findMin(root);
                delFromBST(tmp);
            }
        }
        else if (i > 0) {
            addToBST(i);
        }
        else if (i == 0) {
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