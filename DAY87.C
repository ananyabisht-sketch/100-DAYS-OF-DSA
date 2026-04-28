

#include <stdio.h>

// Function to perform iterative binary search
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;   // target found
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // target not found
}

int main() {
    int n, target;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &target);

    int result = binarySearch(arr, n, target);

    if (result != -1)
        printf("%d", result);
    else
        printf("-1");

    return 0;
}