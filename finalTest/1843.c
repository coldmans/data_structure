#include <stdio.h>
 
#define NV 5    // number of vertices <-- 이것은 고정이니 수정 금지
 
 
void addEdge (int graph[][NV], int v1, int v2, int w){
    graph[v1][v2] = graph[v2][v1] = w;
}
 
void MST_BY_PRIM(int graph[][NV], int start_vertex){
    int visited[NV] = { 0 };
    visited[start_vertex] = 1;
    int cnt = 0, x =-1, y =-1;
    while(cnt < NV -1){
        int m = 999999;
        for(int i= 0; i<NV; i++){
            if(visited[i]){
                for(int j = 0; j < NV; j++){
                    if(!visited[j] && graph[i][j] && graph[i][j] < m){
                        m = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        cnt++;
        visited[y] = 1;
    }
    printf("%d %d", x < y? x:y, x < y? y:x);
}
 
int main(void) {
 
    int v1 = 0;
    int v2 = 0;
    int w = 0;
    int graph[NV][NV] = { 0 };
 
    while (1) {
 
        scanf("%d %d %d", &v1, &v2, &w);
         
        if (v1 < 0) {
            break;
        }
        addEdge(graph, v1, v2, w);
 
    }
 
    MST_BY_PRIM(graph, -v1);
 
    return 0;
 
}
/**************************************************************
    Problem: 1843
    User: DA202101681
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:1084 kb
****************************************************************/