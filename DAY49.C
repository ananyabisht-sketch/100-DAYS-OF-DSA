

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to insert a value into BST
struct TreeNode* insertBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = node->right = NULL;
        return node;
    }
    if (val < root->val) {
        root->left = insertBST(root->left, val);
    } else if (val > root->val) {
        root->right = insertBST(root->right, val);
    }
    return root;
}

// Function to search BST
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;
    if (val < root->val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}

// Inorder traversal to print subtree
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Free memory (optional, good practice)
void freeBST(struct TreeNode* root) {
    if (root == NULL) return;
    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

int main() {
    int n, val;
    printf("Enter number of nodes in BST: ");
    scanf("%d", &n);

    struct TreeNode* root = NULL;
    printf("Enter %d node values: ", n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insertBST(root, x);
    }

    printf("Enter value to search: ");
    scanf("%d", &val);

    struct TreeNode* result = searchBST(root, val);
    if (result != NULL) {
        printf("Subtree rooted at %d (inorder): ", val);
        inorder(result);
        printf("\n");
    } else {
        printf("Node with value %d not found.\n", val);
    }

    freeBST(root);
    return 0;
}