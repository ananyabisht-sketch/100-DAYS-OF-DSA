

#include <stdio.h>

#define INF 1000000000

int main() {
    int n;
    scanf("%d", &n);

    int dist[n][n];

    // Input adjacency matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);

            // Replace -1 with INF (except diagonal)
            if(dist[i][j] == -1 && i != j) {
                dist[i][j] = INF;
            }
        }
    }

    // Floyd-Warshall Algorithm
    for(int via = 0; via < n; via++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][via] != INF && dist[via][j] != INF &&
                   dist[i][via] + dist[via][j] < dist[i][j]) {
                    
                    dist[i][j] = dist[i][via] + dist[via][j];
                }
            }
        }
    }

    // Output shortest distance matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}