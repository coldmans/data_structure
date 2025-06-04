#include <stdio.h>
  
#define INF 1000000000
#define N 6
  
int g[N][N] = {
    {0,2,5,1,0,0},
    {2,0,3,2,0,0},
    {5,3,0,3,1,5},
    {1,2,3,0,1,0},
    {0,0,1,1,0,2},
    {0,0,5,0,2,0}
};
  
int p[N];
int v[N];
int d[N];
  
int getmin(){
    int m = 999999, idx = -1;
    for(int i = 0; i < N; i++){
        if(!v[i] && d[i] < m){
            m = d[i];
            idx = i;
        }
    }
    return idx;
}
  
void printPath(int e){
    if(p[e] == -1){
        printf("%d ",e + 1);
        return;
    }
    printPath(p[e]);
    printf("%d ",e+1);
}
  
void dij(int s, int e){
    for(int i = 0; i<N; i++){
        p[i] = -1;
        d[i] = INF;
        v[i] = 0;
    }
    d[s] = 0;
    for(int i =0; i<N; i++){
        int u = getmin();
        if(u == -1) break;
        v[u] = 1;
        for(int j = 0; j<N; j++){
            if(!v[j] && g[u][j]&& d[u] + g[u][j] < d[j]){ 
                d[j] = d[u] + g[u][j];
                p[j] = u;
            }
        }
    }
    printPath(e);
}
  
int main(void){
    int a,b;
    scanf("%d %d", &a, &b);
    dij(a -1 , b -1);
    return 0;
}