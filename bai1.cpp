#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* right;
	struct Node* left;
} Node;
Node* createNode(int value){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = value;
	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}
Node* insertNode(Node* root, int value){
	if(root == NULL){
		return createNode(value);
	}
	if(value < root->data){
		root->left = insertNode(root->left, value);
	}else if(value > root->data){
		root->right = insertNode(root->right, value);
	}
	return root;
}
void preorder(Node* root){
	if(root == NULL){
		return;
	}
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(Node* root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
void postorder(Node* root){
	if(root == NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}
int main(){
	Node* tree = NULL;
	tree = insertNode(tree,4);
	tree = insertNode(tree,2);
	tree = insertNode(tree,5);
	tree = insertNode(tree,1);
	tree = insertNode(tree,3);
	printf("duyet tien thu tu:\n");
	preorder(tree);
	printf("\nduyet trung thu tu:\n");
	inorder(tree);
	printf("\n duyet hau thu tu:\n");
	postorder(tree);
	return 0;
}

