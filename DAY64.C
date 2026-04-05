#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge to adjacency list
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// BFS function
void BFS(struct Node* adj[], int n, int s) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    // Step 1: push source
    queue[rear++] = s;
    visited[s] = 1;

    printf("BFS Traversal: ");

    while(front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        struct Node* temp = adj[curr];

        while(temp != NULL) {
            int neighbor = temp->data;

            if(!visited[neighbor]) {
                queue[rear++] = neighbor;
                visited[neighbor] = 1;
            }

            temp = temp->next;
        }
    }
}

int main() {
    int n, e;
    struct Node* adj[MAX];

    // Initialize adjacency list
    for(int i = 0; i < MAX; i++) {
        adj[i] = NULL;
    }

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for(int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);
        addEdge(adj, v, u); // remove if directed graph
    }

    int s;
    printf("Enter source vertex: ");
    scanf("%d", &s);

    BFS(adj, n, s);

    return 0;
}