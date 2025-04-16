#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int c = 0;
void hanoi_tower(int n, char from, char tmp, char to, int t) {
    if (n == 1) {
        //제일 작은 원판이 B를 들릴때 c++
        if(to == 'B') c++;
    }
    else {
        hanoi_tower(n - 1, from, to, tmp, t);
        hanoi_tower(n - 1, tmp, from, to, t);
    }
}
int main() {
    int x;
    scanf("%d", &x);
     
    hanoi_tower(x, 'A', 'B', 'C', x);
    printf("%d", c);
    return 0;
}