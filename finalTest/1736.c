#include <stdio.h>
 
int cnt_target_movement = 0;
 
void merge(int n[], int s, int m, int e, int t[], int tar){
    int a = s, b = m +1, k = s;
    int tmp = -1;
    for(int i = s; i<=e; i++){
        if(n[i] == tar){
            tmp = i;
            break;
        }
    }
     
    while(a<=m && b<=e){
        if(n[a] < n[b]) t[k++] = n[a++];
        else t[k++] = n[b++];
    }
    while(a<=m) t[k++] = n[a++];
    while(b <= e) t[k++] = n[b++];
    for(int i = s; i<=e; i++) n[i] =t[i];
    for(int i = s; i<=e; i++){
        if(n[i] == tar && tmp != i) cnt_target_movement++;
    }
}
 
void merge_sort(int nums[], int start, int end, int tarry[], int target_num) {
    if(start < end){
        int mid = (start + end) / 2;
        merge_sort(nums, start, mid, tarry, target_num);
        merge_sort(nums, mid + 1, end, tarry, target_num);
        merge(nums, start, mid, end,  tarry, target_num);   
    }
}
int main(void) {
 
    int i;
    int nums[10] = { 0 };
    int tarry[10] = { 0 };
    int target_num = 0;
 
    for (i = 0; i < 10; i++) {
        scanf("%d", &nums[i]);
    }
    scanf("%d", &target_num);
 
    merge_sort(nums, 0, 9, tarry, target_num);
    printf("%d", cnt_target_movement);
 
    return 0;
}