#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0 || n == 1) {
        printf("%d", n);
        return 0;
    }

    int low = 1, high = n, ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid * mid == n) {
            printf("%lld", mid);
            return 0;
        }
        else if (mid * mid < n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("%d", ans);

    return 0;
}