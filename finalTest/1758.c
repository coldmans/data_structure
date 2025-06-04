#include <stdio.h>
 
#define INF 1000000000
#define N 100
 
int p[N];
int d[N];
int v[N];
 
void addEdge(int g[][N] , int x, int y, int w){
    g[x][y] = g[y][x] = w;
}
 
int getmin(int n){
    int m = 999999, idx = -1;
    for(int i = 0; i<n; i++){
        if(!v[i] && d[i] < m){
            m = d[i];
            idx = i;
        }
    }
    return idx;
}
 
void printPath(int e){
    if(p[e] == -1){
        printf("%d ",e);
        return;
    }
    printPath(p[e]);
    printf("%d ",e);
}
 
void dij(int g[][N], int s, int e, int n){  
    for(int i =0; i < n; i++){
        p[i] = -1;
        d[i] = INF;
        v[i] = 0;   
    }
    d[s] = 0;
    for(int i = 0; i<n; i++){
        int u = getmin(n);
        if(u == -1) break;
        v[u] = 1;
        for(int j = 0; j<n; j++){
            if(!v[j] && g[u][j] && d[u] + g[u][j] < d[j]){
                d[j] = d[u] + g[u][j];
                p[j] = u;
            }
        }
    }
    printPath(e);
    printf("%d\n", d[e]);
}
 
int main(){
    int n,e,x,y,w,c;
    int g[N][N];
    scanf("%d %d", &n, &e);
    for(int i =0; i<e; i++){
        scanf("%d %d %d", &x, &y, &w);
        addEdge(g,x,y,w);
    }
    scanf("%d", &c);
    for(int i = 0; i<c; i++){
        scanf("%d %d", &x,&y);
        dij(g,x,y,n);
    }
    return 0;
}
 
/**************************************************************
    Problem: 1758
    User: DA202101681
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:1084 kb
****************************************************************/