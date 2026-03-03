

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *arr;
    int top;
    int capacity;
};


void initStack(struct Stack *s, int capacity) {
    s->capacity = capacity;
    s->top = -1;
    s->arr = (int *)malloc(capacity * sizeof(int));
}


void push(struct Stack *s, int value) {
    if (s->top == s->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = value;
}


void pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", s->arr[(s->top)--]);
}


void display(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is Empty\n");
        return;
    }
    
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct Stack s;
    initStack(&s, n);  

    for (int i = 0; i < n; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int value;
            scanf("%d", &value);
            push(&s, value);
        }
        else if (type == 2) {
            pop(&s);
        }
        else if (type == 3) {
            display(&s);
        }
    }

    free(s.arr);
    return 0;
}