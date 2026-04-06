#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100005

// Adjacency list
int *adj[MAX];
int adjSize[MAX];
bool visited[MAX];

// DFS function
bool dfs(int node, int parent) {
    visited[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle found
        }
    }
    return false;
}

// Function to detect cycle
bool hasCycle(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        adj[i] = (int *)malloc(MAX * sizeof(int));
        adjSize[i] = 0;
        visited[i] = false;
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u; // undirected
    }

    if (hasCycle(V))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}