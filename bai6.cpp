#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Hàm ki?m tra tính ch?t BST
bool isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL) {
        return true;
    }

    if (root->data <= min || root->data >= max) {
        return false;
    }

    return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
}

bool isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
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
    struct Node* root = createNode(10);
    addChild(root, 5, 15);
    addChild(root->left, 3, 7);
    addChild(root->right, 12, 20);

    // Hi?n th? cây theo th? t? tru?c
    printf("Cay theo thu tu truoc: \n");
    displayTree(root);

    // Ki?m tra tính ch?t BST và hi?n th? k?t qu?
    if (isBST(root)) {
        printf("\n\nCay la mot Binary Search Tree (BST).\n");
    } else {
        printf("\n\nCay khong phai la mot Binary Search Tree (BST).\n");
    }

    return 0;
}

