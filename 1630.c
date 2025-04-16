#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fibo(int i) {
    if (i <= 1)
        return i;
    int a = 0;
    int b = 1;
    int result;
    for (int x = 2; x <= i; x++) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}
int main() {
    int i;
    scanf("%d", &i);
    printf("%d", fibo(i));
    return 0;
}