
#include <stdio.h>
#define MAX 1000

int stack[MAX];
int top = -1;

/* Push function */
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

/* Pop function */
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

int main() {
    int n, m, i, value;

    // Read number of elements
    scanf("%d", &n);

    // Push n elements
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // Read number of pops
    scanf("%d", &m);

    // Perform m pops
    for (i = 0; i < m; i++) {
        pop();
    }

    // Print remaining stack from top to bottom
    if (top == -1) {
        printf("Stack is empty");
    } else {
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
    }

    return 0;
}