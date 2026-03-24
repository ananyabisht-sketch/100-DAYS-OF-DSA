
#include <stdio.h>
#include <stdlib.h>

// Step 1: Define structure
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Step 2: Create node
TreeNode* createNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Step 3: Build tree from level order array
TreeNode* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    TreeNode* root = createNode(arr[i]);

    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Step 4: Find LCA
TreeNode* LCA(TreeNode* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (root->val == p || root->val == q)
        return root;

    TreeNode* left = LCA(root->left, p, q);
    TreeNode* right = LCA(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;

    return (left != NULL) ? left : right;
}

// Step 5: Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    TreeNode* root = buildTree(arr, n, 0);

    int p, q;
    scanf("%d %d", &p, &q);

    TreeNode* ans = LCA(root, p, q);

    if (ans != NULL)
        printf("%d\n", ans->val);
    else
        printf("Not found\n");

    return 0;
}