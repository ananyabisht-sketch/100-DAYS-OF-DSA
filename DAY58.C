#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findIndex(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int preStart, int preEnd, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    Node* root = createNode(preorder[preStart]);

    int inIndex = findIndex(inorder, inStart, inEnd, root->data);
    int leftSize = inIndex - inStart;

    root->left = buildTree(preorder, inorder,
                           preStart + 1, preStart + leftSize,
                           inStart, inIndex - 1);

    root->right = buildTree(preorder, inorder,
                            preStart + leftSize + 1, preEnd,
                            inIndex + 1, inEnd);

    return root;
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    Node* root = buildTree(preorder, inorder, 0, n - 1, 0, n - 1);

    postorder(root);

    return 0;
}