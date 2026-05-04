
#include <stdio.h>

// Function to check if we can paint within maxTime using k painters
int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime + boards[i] <= maxTime) {
            currentTime += boards[i];
        } else {
            painters++;
            currentTime = boards[i];

            if (painters > k)
                return 0; // not possible
        }
    }
    return 1; // possible
}

int minTime(int boards[], int n, int k) {
    int left = 0, right = 0;

    // Find max element and sum
    for (int i = 0; i < n; i++) {
        if (boards[i] > left)
            left = boards[i];
        right += boards[i];
    }

    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            right = mid - 1; // try smaller time
        } else {
            left = mid + 1;  // increase time
        }
    }

    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d\n", minTime(boards, n, k));
    return 0;
}