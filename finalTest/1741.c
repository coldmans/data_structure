#include <stdio.h>
 
 
 
int do_insertion_sort(int _data[], int _sz, int _num){
    int j,m;
    int ctt = 0;
    for(int i = 1; i<_sz; i++){
        m = _data[i];
        for(j = i-1; j>=0 && _data[j] > m;  j--){
            _data[j+1] = _data[j];
            if(_data[j] == _num) ctt++;
        }
        _data[j+1] = m;
        if(j != i-1 && _num == m) ctt++;
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
     
    res = do_insertion_sort(data, 10, d);
     
    printf("%d", res);
    return 0;
}
/**************************************************************
    Problem: 1741
    User: DA202101681
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:1084 kb
****************************************************************/