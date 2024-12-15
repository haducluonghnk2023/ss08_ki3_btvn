#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;               
    struct Node* left ;  
    struct Node* right; 
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addChild(Node* parent, int value) {
    Node* child = createNode(value);
    if (parent->left == NULL) {
        parent->left = child;
    } else {
        Node* temp = parent->left;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        temp->right = child;
    }
}
void findAndPrintLevel2(Node* root) {
    if (root == NULL) return;

    Node* child = root->left;
    if (child == NULL) { 
        printf("khong co dinh lop 2\n");
        return;
    }

    int found = 0; 
    while (child != NULL) {
        Node* grandChild = child->left; 
        while (grandChild != NULL) {
            if (!found) {
                printf("Cac dinh lop 2: "); 
                found = 1; 
            }
            printf("%d ", grandChild->data);
            grandChild = grandChild->right;
        }
        child = child->right;
    }

    if (!found) {
        printf("khong co dinh lop 2\n");
    } else {
        printf("\n");
    }
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = createNode(1);
    addChild(root, 1);
    addChild(root, 2);
    addChild(root->left, 4);    
    addChild(root->left, 5);   
    addChild(root->left->right, 6);
	addChild(root->left->right, 7);

    findAndPrintLevel2(root);

    freeTree(root);

    return 0;
}
	
