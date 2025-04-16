#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
struct A {
    int age;
    int weight;
};
 
//------아래 부분은 절대 손대지 마세요 ------------------
 
int main(void) {
 
    struct A k;
    int a, b;
    scanf("%d %d", &a, &b);
 
    k.age = a;
    k.weight = b;
 
    printf("%d", k.age + k.weight);
    return 0;
}