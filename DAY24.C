
#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {
    
    // If list is empty
    if (head == NULL)
        return head;

    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head contains key
    if (temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search for key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if (temp == NULL)
        return head;

    // Unlink node
    prev->next = temp->next;
    free(temp);

    return head;
}

// Function to print list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, key, value;

    struct Node* head = NULL;
    struct Node* tail = NULL;

    scanf("%d", &n);

    // Create linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &key);

    // Delete first occurrence
    head = deleteKey(head, key);

    // Print result
    printList(head);

    return 0;
}