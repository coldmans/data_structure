#include <stdio.h>
#include <stdlib.h>
 
#define SZ 100
 
int myheap[SZ];
int heap_size = 0;
 
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
 
void heapup(int index){
    while(index> 1){
        int p = index / 2;
        if(myheap[p] > myheap[index]) return;
        swap(&myheap[p], &myheap[index]);
        index = p;
    }
}
 
void enqueue(int v){
    if(heap_size == SZ) return;
    for(int i = 0; i < SZ; i++){
        if(myheap[i] == v){
            myheap[i]++;
            return;
        }
    }
    myheap[++heap_size] = v;
    heapup(heap_size);
}
 
void heapdown(int index){
    while(1){
        int max = index;
        int left = index * 2;
        int right = index * 2 + 1;
        if(left <= heap_size && myheap[max] < myheap[left])
            max = left;
        if(right <= heap_size && myheap[max] < myheap[right])
            max = right;
        if(max == index) return;
        swap(&myheap[max], &myheap[index]);
        index = max;
    }
}
 
int dequeue(){
    if(heap_size == 0) return -999;
    int max = myheap[1];
    myheap[1] = myheap[heap_size--];
    heapdown(1);
    return max;
}
 
int main(void) {
 
    int d;
    int i;
 
    while (1) {
        scanf("%d", &d);
        if (d == 999) {
            break;
        }
        enqueue(d);
    }
    while(1){
        if(heap_size == 0) return 0;
        printf("%d ", dequeue());
 
    }   
    return 0;
}
/**************************************************************
    Problem: 1839
    User: DA202101681
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:1084 kb
****************************************************************/