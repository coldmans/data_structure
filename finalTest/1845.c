#include <stdio.h>
 
#define INF 1000000000
#define N 6
 
int g[N][N] = {
    {0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
    {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INF},
    {INF, INF, 1, 1, 0, 2},
    {INF, INF, 5, INF, 2, 0}
};
 
int d[N];
int p[N];
int v[N];
 
int getmin(){
    int m = 999999, idx = -1;
    for(int i = 0; i<N; i++){
        if(!v[i] && d[i] < m){
            m = d[i];
            idx = i;
        }
    }
    return idx;
}
 
void printPath(int e){
    if(p[e] == -1){
        printf("%d ",e +1);
        return;
    }
    printPath(p[e]);
    printf("%d ", e+ 1);
}
 
 
void dij(int s, int e){
    for(int i =0; i< N; i++){
        d[i] = INF;
        p[i] = -1;
        v[i] = 0;
    }
    d[s] = 0;
    for(int i = 0; i<N; i++){
        int u = getmin();
        if(u == -1) break;
        v[u] = 1;
        for(int j = 0; j<N; j++){
            if(!v[j] && g[u][j] && d[u] + g[u][j] < d[j]){
                d[j] = d[u] + g[u][j];  
                p[j] = u;
            }
        }
    }
    printPath(e);
}
 
int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    dij(a -1, b -1);
    return 0;
}
 
 
 
 
/**************************************************************
    Problem: 1845
    User: DA202101681
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:1084 kb
****************************************************************/