#include <stdio.h>
#define SZ 20
 
int data[SZ];
int size = 0;
 
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
 
void heapup(int index){
    while(index > 1){
        int p = index / 2;
        if(data[p] > data[index]) return;
        swap(&data[p], &data[index]);
        index = p;
    }
}
 
void enque(int v){
    if(size == SZ) return;
    data[++size] = v;
    heapup(size);
}
 
void heapdown(int index){
    while(1){
        int max = index;
        int left = index * 2;
        int right = left + 1;
        if(left <= size && data[max] < data[left]) max = left;
        if(right <= size && data[max] < data[right]) max = right;
        if(max == index) return;
        swap(&data[max], &data[index]);
        index = max;
    }
}
 
void deque(int a){
    int i = 0;
    if(size == 0) return -999;
    for(i = 0; i<SZ; i++){
        if(data[i] == a) break;
    }
    data[i] = data[size--];
    heapdown(i);
}
 
 
int main(){
    int t,a;
    scanf("%d",&t);
    for(int i = 0; i<t; i++){
        scanf("%d",&a);
        enque(a);
    }
    scanf("%d" , &a);
    deque(a);
    for(int i =1; i<t; i++) printf("%d ",data[i]);
    return 0;
}
 
 
/**************************************************************
    Problem: 1824
    User: DA202101681
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:1084 kb
****************************************************************/