#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// C?u tr�c m?t n�t trong c�y
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// H�m t?o m?t n�t m?i
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// H�m th�m n�t con v�o c�y (theo c?u tr�c c? d?nh)
void addChild(struct Node* parent, int leftData, int rightData) {
    if (parent == NULL) return;
    
    if (leftData != -1) {
        parent->left = createNode(leftData);
    }
    if (rightData != -1) {
        parent->right = createNode(rightData);
    }
}

// H�m ki?m tra t�nh ch?t BST
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

// H�m hi?n th? c�y theo th? t? tru?c (Preorder Traversal)
void displayTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    displayTree(root->left);
    displayTree(root->right);
}

int main() {
    // T?o c�y c? d?nh
    struct Node* root = createNode(10);
    addChild(root, 5, 15);
    addChild(root->left, 3, 7);
    addChild(root->right, 12, 20);

    // Hi?n th? c�y theo th? t? tru?c
    printf("Cay theo thu tu truoc: \n");
    displayTree(root);

    // Ki?m tra t�nh ch?t BST v� hi?n th? k?t qu?
    if (isBST(root)) {
        printf("\n\nCay la mot Binary Search Tree (BST).\n");
    } else {
        printf("\n\nCay khong phai la mot Binary Search Tree (BST).\n");
    }

    return 0;
}

