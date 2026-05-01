
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int counts[]) {
    int i = left, j = mid + 1, k = 0;
    int rightCount = 0;

    Pair* temp = (Pair*)malloc(sizeof(Pair) * (right - left + 1));

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            counts[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        counts[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

    free(temp);
}

void mergeSort(Pair arr[], int left, int right, int counts[]) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, counts);
    mergeSort(arr, mid + 1, right, counts);

    merge(arr, left, mid, right, counts);
}

int* countSmaller(int* nums, int n) {
    Pair* arr = (Pair*)malloc(sizeof(Pair) * n);
    int* counts = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, 0, n - 1, counts);

    free(arr);
    return counts;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(sizeof(int) * n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int* result = countSmaller(nums, n);

    printf("Output:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    free(nums);
    free(result);

    return 0;
}