

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* append(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}


struct Node* findNode(struct Node* head, int value) {
    while (head != NULL) {
        if (head->data == value)
            return head;
        head = head->next;
    }
    return NULL;
}


int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    
    if (len1 > len2) {
        while (diff--)
            head1 = head1->next;
    } else {
        while (diff--)
            head2 = head2->next;
    }

    
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int n, m, i, value;
    struct Node *head1 = NULL, *head2 = NULL;

    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = append(head1, value);
    }

    
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &value);

        
        struct Node* intersectNode = findNode(head1, value);

        if (intersectNode != NULL) {
            
            if (head2 == NULL)
                head2 = intersectNode;
            else {
                struct Node* temp = head2;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = intersectNode;
            }
            break;  
        } else {
            head2 = append(head2, value);
        }
    }

    
    struct Node* result = getIntersection(head1, head2);

    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    return 0;
}