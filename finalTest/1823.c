#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
#define SZ 11
 
int data[SZ];
int size = 0;
 
 
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void heapup(int index) {
    while (index > 1) {
        int p = index / 2;
        if (data[p] < data[index]) return;
        swap(&data[p], &data[index]);
        index = p;
    }
}
 
void add_node(int v) {
    if (size == SZ) return;
    size++;
    data[size] = v;
    heapup(size);
}
 
int max_print() {
    int max = data[1];
    int i = 0;
    while (1) {
        if (i == size + 1) break;
 
        if (data[i] > max)
            max = data[i];
        i++;
    }
    return max;
}
 
 
int main(void) {
    int c;
    while (1) {
        scanf("%d ", &c);
        if (c > 0) {
            add_node(c);
        }
 
        if (c == -1) {
            printf("%d", data[1]);
            return 0;
        }
        if (c == -2) {
            printf("%d", max_print());
            return 0;
        }
    }
    return 0;
}
/**************************************************************
    Problem: 1823
    User: DA202101681
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:1084 kb
****************************************************************/