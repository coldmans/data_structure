#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
int sumFromNtoOne(int n) {
    int result = 0;
    if (n == 1) {
        return 1;
    }
    result = n + sumFromNtoOne(n - 1);
    return result;
}
 
// --- 이하 수정 금지 ---
int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n",sumFromNtoOne(n));
 
    return 0;
}