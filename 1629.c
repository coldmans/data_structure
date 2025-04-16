#include <stdio.h>
int fibo(int i) {
    if (i <= 1)
        return i;
    return fibo(i-1) + fibo(i - 2);
}
int main() {
    int i;
    scanf("%d", &i);
    printf("%d", fibo(i));
    return 0;
}