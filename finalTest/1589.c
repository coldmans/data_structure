#include <stdio.h>
 
#define NV 6    // number of vertices <-- 이것은 고정이니 수정 금지
 
int top = -1;
int data[NV];
int v[NV] = { 0 };
 
void push(int v){
    if(top < NV -1) data[++top] =v;
}
 
int pop(){
    if(top == -1) return -999;
    return data[top--];
}
 
void addEdge (int graph[][NV], int v1, int v2){
    graph[v1][v2] = graph[v2][v1] = 1;
}
 
void adj(int g[][NV], int s){
    for(int i = 0; i<NV; i++)
        if(!v[i] && g[s][i]) push(i);
}      
 
void DepthFirstSearch(int graph[][NV], int start_vertex){
    push(start_vertex);
    while(1){
        if(top == -1) return;
        int u = pop();
        if( u == -999) return;
        if(!v[u]){
            v[u] = 1;
            printf("%d ",u);
            adj(graph, u);
        }
    }
}
 
int main(void) {
 
    int v1 = 0;
    int v2 = 0;
    int graph[NV][NV] = { 0 };
 
    while (1) {
 
        scanf("%d %d", &v1, &v2);
         
        if (v1 < 0) {
            break;
        }
        addEdge(graph, v1, v2);
 
    }
 
    DepthFirstSearch(graph, -v1);
 
    return 0;
 
}
/**************************************************************
    Problem: 1589
    User: DA202101681
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:1084 kb
****************************************************************/