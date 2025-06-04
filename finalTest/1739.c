#include <stdio.h>
int ctt = 0;
void swap(int *a, int *b, int n){
    if(n == *a || n == *b) ctt++;
    int t = *a;
    *a = *b;
    *b = t;
}
int do_bubble_sort(int _data[], int _sz, int _num){
    for(int i = _sz; i>= 0; i--){
        for(int j =0; j<i; j++){
            if(_data[j] > _data[j+1]) swap(&_data[j+1], &_data[j], _num);
        }
    }
    return ctt;
}
 
int main(void) {
 
    int data[10]= {0};
    int d, i;
    int res;
    for (i = 0; i < 10; i++) {
        scanf("%d", &d);
        data[i] = d;
    }
    scanf("%d", &d);
     
    res = do_bubble_sort(data, 10, d);
     
    printf("%d", res);
    return 0;
}
/**************************************************************
    Problem: 1739
    User: DA202101681
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:1084 kb
****************************************************************/