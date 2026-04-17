/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node* dfs(struct Node* node, struct Node** visited) {
    if (node == NULL)
        return NULL;

    if (visited[node->val] != NULL)
        return visited[node->val];

    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;

    if (node->numNeighbors > 0)
        clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);
    else
        clone->neighbors = NULL;

    visited[node->val] = clone;

    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i], visited);
    }

    return clone;
}

struct Node* cloneGraph(struct Node* node) {
    struct Node* visited[101] = {NULL};
    return dfs(node, visited);
}