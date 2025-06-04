#include <stdio.h>
int ctt = 0;
void swap(int *a, int *b, int n){
    if(n == *a || n== *b) ctt++;
    int t = *a;
    *a = *b;
    *b =t;
}
 
int do_selection_sort(int _data[], int _sz, int _num){
    int m;
    for(int i = 0; i<_sz; i++){
        m = i;
        for(int j = i +1; j<_sz; j++){
            if(_data[j] < _data[m]) m = j;
        }
        if(m != i) swap(&_data[i], &_data[m], _num);
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
     
    res = do_selection_sort(data, 10, d);
     
    printf("%d", res);
    return 0;
}
/**************************************************************
    Problem: 1740
    User: DA202101681
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:1084 kb
****************************************************************/