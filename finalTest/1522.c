#include <stdio.h>
#define SZ 100
// max heap
 
int data[SZ];
int size = 0;
 
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
 
void heapup(int v) {
    while (v > 1) {
        int p = v / 2;
        if (data[p] > data[v]) return;
        swap(&data[p], &data[v]);
        v = p;
    }
}
 
void heapdown(int index) {
    while (1) {
        int max = index;
        int left = index * 2;
        int right = index * 2 + 1;
        if (left <= size && data[max] < data[left])
            max = left;
        if (right <= size && data[max] < data[right])
            max = right;
        if (max == index) return;
        swap(&data[max], &data[index]);
        index = max;
    }
}
 
int deque(){
    if (size == 0) return -999;
    int max = data[1];
    data[1] = data[size--];
    heapdown(1);
    return max;
}
 
void enque(int v) {
    if (size == SZ) return;
    int i = 1;
    while (1) {
        if (i == size + 1) break;
        if (data[i] == v) {
            data[i]++;
            heapup(i);
            return;
        }
        i++;
    }
    data[++size] = v;
    heapup(size);
}
 
int main(void) {
    int c;
    while (1) {
        scanf("%d", &c);
        if (c == 999) {
            while (1) {
                if (size == 0) return 0;
                printf("%d ", deque());
            }
        }
        else if (c > 0)
            enque(c);
         
    }
 
}
 
 
 
/**************************************************************
    Problem: 1522
    User: DA202101681
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:1084 kb
****************************************************************/