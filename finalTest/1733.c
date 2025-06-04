#include <stdio.h>
 
#define NV 5    // number of vertices <-- 이것은 고정이니 수정 금지
 
int findRoot(int p[], int v){
    if(p[v] == v) return v;
    return p[v] = findRoot(p,p[v]);
}
 
void unionSets(int p[], int a, int b){
    a = findRoot(p,a);
    b = findRoot(p,b);
    if(a < b) p[b] = a;
    else p[a] = b;
}
 
void addEdge (int graph[][NV], int v1, int v2, int w){
    graph[v1][v2]  = graph[v2][v1] = w;
}
 
void MST_BY_KRUSKAL(int graph[][NV]){
    int p[NV];
    for(int i = 0; i<NV; i++) p[i] = i;
    int cnt = 0;
    while(cnt <NV -1){
        int m = 999999, x = -1, y = -1;
        for(int i = 0; i<NV; i++){
            for(int j = 0; j<NV; j++){
                if(graph[i][j] && graph[i][j] < m){
                    m = graph[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        if(x == -1) break;
        int a = findRoot(p,x);
        int b = findRoot(p,y);
        if (a == b) printf("%d\n", x + y);
        else{
            cnt++;
            unionSets(p,a,b);
        }
        graph[x][y] = graph[y][x] = 0;
    }
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
 
    MST_BY_KRUSKAL(graph);
 
    return 0;
 
}