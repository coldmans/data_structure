#include <stdio.h>
 
#define NV 6    // number of vertices <-- 이것은 고정이니 수정 금지
 
int data[NV];
int rear = 0, front = 0;
int v[NV] = {0};
 
void enque(int v){
    if(front == (rear +1) % NV) return;
    rear = (rear +1) % NV; 
    data[rear] = v;
}
 
int deque(){
    if(front == rear) return -999;
    front = (front + 1) % NV;
    return data[front];
}
 
void addEdge (int graph[][NV], int v1, int v2){
    graph[v1][v2] = graph[v2][v1] = 1;
}
 
void adj(int g[][NV], int s){
    for(int i = 0; i<NV; i++){
        if(g[s][i] && !v[i]) enque(i);
    }
}
 
void BreadthFirstSearch(int graph[][NV], int start_vertex){
    enque(start_vertex);
    while(1){
        int u = deque();
        if(u == -999) return;
        if(!v[u]){
            v[u] = 1;
            printf("%d ", u);
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
 
    BreadthFirstSearch(graph, -v1);
 
    return 0;
 
}