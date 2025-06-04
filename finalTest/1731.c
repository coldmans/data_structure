#include <stdio.h>
 
#define SZ 6
 
void topo(int g[SZ][SZ], int d[SZ]) {
    int v[SZ] = {0};
    for (int k = 0; k < SZ; k++) {
        for (int i = 0; i < SZ; i++) {
            if (d[i] == 0 && !v[i]) {
                v[i] = 1;
                printf("%d", i);
                for (int j = 0; j < SZ; j++) 
                    if (g[i][j]) d[j]--;
                if (k < SZ - 1) printf(" ");
                break;
            }
        }
    }
}
 
int main() {
    int g[SZ][SZ] = {0};
    int d[SZ] = {0};
 
    while (1) {
        int s, t;
        scanf("%d %d", &s, &t);
        if (s == -1 && t == -1) break;
        g[s][t] = 1;
        d[t]++;
    }
    topo(g, d);
    return 0;
}