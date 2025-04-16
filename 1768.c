#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
 
int fibo(int ctt) {
    int result = 0;
    if (ctt <= 2)
        return 1;
 
    result = fibo(ctt -1) + fibo(ctt - 2) ;
    return result;
}
 
 
int main(void) {
 
    int a;
    scanf("%d", &a);
 
    printf("%d",fibo(a));
 
    return 0;
}