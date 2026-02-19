

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    
    qsort(arr, n, sizeof(int), compare);
    
    int left = 0;
    int right = n - 1;
    
    int min_sum = INT_MAX;
    int ans1, ans2;
    
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            ans1 = arr[left];
            ans2 = arr[right];
        }
        
        if (sum < 0)
            left++;
        else
            right--;
    }
    
    printf("%d %d\n", ans1, ans2);
    
    return 0;
}
