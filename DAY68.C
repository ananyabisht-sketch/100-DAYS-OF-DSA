
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

// Queue for Topological Sort
int queue[MAX], front = 0, rear = 0;

void push(int x) {
    queue[rear++] = x;
}

int pop() {
    return queue[front++];
}

// Function to find alien dictionary order
char* findOrder(char words[][20], int n, int k) {
    static char result[MAX + 1];

    int graph[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    // Step 1: Build graph from adjacent words
    for (int i = 0; i < n - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];

        int len1 = strlen(w1);
        int len2 = strlen(w2);
        int minLen = len1 < len2 ? len1 : len2;

        int found = 0;
        for (int j = 0; j < minLen; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';

                if (!graph[u][v]) {
                    graph[u][v] = 1;
                    indegree[v]++;
                }
                found = 1;
                break;
            }
        }

        // Invalid case: prefix problem
        if (!found && len1 > len2)
            return "";
    }

    // Step 2: Push all 0 indegree nodes into queue
    for (int i = 0; i < k; i++) {
        if (indegree[i] == 0)
            push(i);
    }

    // Step 3: Topological Sort (Kahn’s Algorithm)
    int idx = 0;
    while (front < rear) {
        int u = pop();
        result[idx++] = u + 'a';

        for (int v = 0; v < k; v++) {
            if (graph[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    push(v);
            }
        }
    }

    result[idx] = '\0';

    // If cycle exists, invalid order
    if (idx != k)
        return "";

    return result;
}

// Driver Code
int main() {
    int n = 5, k = 4;
    char words[5][20] = {"baa", "abcd", "abca", "cab", "cad"};

    char *order = findOrder(words, n, k);

    if (strlen(order) == 0)
        printf("Invalid Dictionary Order\n");
    else
        printf("Alien Dictionary Order: %s\n", order);

    return 0;
}


