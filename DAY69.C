#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 100
#define INF INT_MAX

// Adjacency list node
typedef struct Node {
    int vertex, weight;
    struct Node* next;
} Node;

// Min Heap node
typedef struct HeapNode {
    int vertex, dist;
} HeapNode;

// Min Heap structure
typedef struct MinHeap {
    int size;
    HeapNode heap[V];
} MinHeap;

// Create adjacency node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(Node* adj[], int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Swap heap nodes
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(MinHeap* h, int idx) {
    while (idx && h->heap[(idx - 1) / 2].dist > h->heap[idx].dist) {
        swap(&h->heap[(idx - 1) / 2], &h->heap[idx]);
        idx = (idx - 1) / 2;
    }
}

// Heapify down
void heapifyDown(MinHeap* h, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        swap(&h->heap[idx], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

// Insert into heap
void insertHeap(MinHeap* h, int vertex, int dist) {
    h->heap[h->size].vertex = vertex;
    h->heap[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

// Extract minimum
HeapNode extractMin(MinHeap* h) {
    HeapNode root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

// Dijkstra Algorithm
void dijkstra(Node* adj[], int n, int src) {
    int dist[V];
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    MinHeap h;
    h.size = 0;

    dist[src] = 0;
    insertHeap(&h, src, 0);

    while (h.size > 0) {
        HeapNode minNode = extractMin(&h);
        int u = minNode.vertex;

        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                insertHeap(&h, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print shortest distances
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++)
        printf("To %d = %d\n", i, dist[i]);
}

// Main function
int main() {
    int n = 5;
    Node* adj[V] = {NULL};

    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 5);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 1, 4, 2);
    addEdge(adj, 2, 3, 4);
    addEdge(adj, 3, 0, 7);
    addEdge(adj, 4, 1, 3);
    addEdge(adj, 4, 2, 9);
    addEdge(adj, 4, 3, 2);

    dijkstra(adj, n, 0);

    return 0;
}