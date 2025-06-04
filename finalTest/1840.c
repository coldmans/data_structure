#include <stdio.h>
 
#define NV 6    
int data[NV];
int top = -1;
int v[NV] = { 0 };
 
 void addEdge (int g[][NV], int x, int y){
    g[x][y] = g[y][x] = 1;
}
     
void push(int v){
    if(top < NV -1)
        data[++top] = v;
}
 
int pop(){
    if(top == -1) return -999;
    return data[top--];
}
 
void adj(int g[][NV], int a){
    for(int i = 0; i < NV; i++){
        if(g[a][i] && !v[i])
            push(i);
    }
 
}
 
 void DepthFirstSearch(int g[][NV], int st){
    push(st);
    while(1){
        if(top == -1) return;
        int s=pop();
        if(s == -999) return;
        if(!v[s]){
            v[s] = 1;
            printf("%d ",s);
            adj(g, s);
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
    Problem: 1840
    User: DA202101681
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:1084 kb
****************************************************************/