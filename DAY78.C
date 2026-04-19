
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

int minKey(int key[], int n) {
    int min = INT_MAX, minIndex = -1;

    for(int i = 1; i <= n; i++) {
        if(!visited[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            graph[i][j] = 0;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[MAX];
    for(int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;
    int total = 0;

    for(int count = 1; count <= n; count++) {
        int u = minKey(key, n);
        visited[u] = 1;
        total += key[u];

        for(int v = 1; v <= n; v++) {
            if(graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d", total);

    return 0;
}