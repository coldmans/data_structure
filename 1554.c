#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
int recursion(int i) {
    if (i == 1)
        return 1;
    return i + recursion(i - 1);
}
 
 
int main(void) {
    int i;
    scanf("%d", &i);
    printf("%d",recursion(i));
    return 0;
 
}