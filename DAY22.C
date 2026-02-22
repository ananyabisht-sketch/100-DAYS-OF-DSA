
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory
    if (newNode == NULL) {
        printf("Memory allocation failed\\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode; 
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) { 
            temp = temp->next;
        }
        temp->next = newNode; 
    }
    return head;
}


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    }
    printf("\\n");
}


int main() {
    int n, value;
    struct Node* head = NULL;

    
    printf("Input the number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for number of nodes.\\n");
        return 1;
    }

    
    printf("Input the %d space-separated integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1) {
            printf("Invalid input for node value.\\n");
            return 1;
        }
        head = insertEnd(head, value); 
    }

    
    printf("Output: ");
    printList(head);

    
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

