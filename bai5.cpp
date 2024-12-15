#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;         
    struct Node* left;  
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* search(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);  
        printf("%d ", root->data);    
        inorder(root->right); 
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    printf("Inorder : ");
    inorder(root);
    printf("\n");
    int searchValue = 40;
    Node* foundNode = search(root, searchValue);
    if (foundNode != NULL) {
        printf("gia tri %d ton tai trong cay.\n", searchValue);
    } else {
        printf("gia tri %d khong ton tai trong cay.\n", searchValue);
    }
    freeTree(root);
    
    return 0;
}

