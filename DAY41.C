

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue operation
void dequeue() {
    if(front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", front->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

int main() {

    int N, op, value;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &op);

        if(op == 1) {      // Enqueue
            scanf("%d", &value);
            enqueue(value);
        }
        else if(op == 2) { // Dequeue
            dequeue();
        }
    }

    return 0;
}