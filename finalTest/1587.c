#include <stdio.h>
 
int pivot_left = -999;
int pivot_right = -999;
 
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
 
void quick_sort(int nums[], int start, int end, int real_size, int pivot_value) {
    int p = start, low = start +1, high = end;
    if(start >= end) return;
    while(low<=high){
        while(low <= end && nums[low] <= nums[p]) low++;
        while(high > start && nums[high] >= nums[p]) high--;
        if(low < high) swap(&nums[low] , &nums[high]); 
    }
    swap(&nums[p] , &nums[high]);
    if(nums[high] == pivot_value){
        pivot_left = nums[high-1];
        pivot_right = nums[high+1];
    }
    quick_sort(nums,start,high-1,real_size, pivot_value);
    quick_sort(nums, high+1,end, real_size, pivot_value);
}
 
int main(void) {
 
    int i;
    int pivot = 0;
    int nums[10] = { 0 };
 
 
    for (i = 0; i < 10; i++) {
        scanf("%d", &nums[i]);
    }
    scanf("%d", &pivot);
 
    quick_sort(nums, 0, 9, 10, pivot);
    printf("%d %d", pivot_left, pivot_right);
 
    return 0;
}
/**************************************************************
    Problem: 1587
    User: DA202101681
    Language: C
    Result: Accepted
    Time:1 ms
    Memory:1084 kb
****************************************************************/