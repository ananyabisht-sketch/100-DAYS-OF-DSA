
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int left, right;
    char temp;

    // Read input string
    scanf("%s", s);

    left = 0;
    right = strlen(s) - 1;

    // Reverse the string
    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }

    // Print result
    printf("%s", s);

    return 0;
}
