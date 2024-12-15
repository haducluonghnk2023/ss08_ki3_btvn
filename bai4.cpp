#include <stdio.h>
#include <stdlib.h>

// C?u trúc m?t nút trong cây
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Hàm t?o m?t nút m?i
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm thêm nút con vào cây (theo c?u trúc c? d?nh)
void addChild(struct Node* parent, int leftData, int rightData) {
    if (parent == NULL) return;
    
    if (leftData != -1) {
        parent->left = createNode(leftData);
    }
    if (rightData != -1) {
        parent->right = createNode(rightData);
    }
}

// Hàm tính chi?u cao c?a cây
int calculateHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Hàm hi?n th? cây theo th? t? tru?c (Preorder Traversal)
void displayTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    displayTree(root->left);
    displayTree(root->right);
}

int main() {
    // T?o cây c? d?nh
    struct Node* root = createNode(1);
    addChild(root, 2, 3);
    addChild(root->left, 4, 5);
    addChild(root->right, 6, -1);

    // Hi?n th? cây theo th? t? tru?c
    printf("Cay theo thu tu truoc: \n");
    displayTree(root);

    // Tính và hi?n th? chi?u cao c?a cây
    int height = calculateHeight(root);
    printf("\n\nChieu cao cua cay: %d\n", height);

    return 0;
}

