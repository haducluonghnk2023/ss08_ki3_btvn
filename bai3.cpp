#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Node;
Node* createNode(int value) {
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
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
int searchBST(Node* root, int value){
	if(root == NULL){
		return 0;
	}
	if(root->data == value){
		return 1;
	}
	if(value < root->data){
		return searchBST(root->left, value);
	}else {
		return searchBST(root->right, value);
	}
}
void freeTree(Node* root){
	if(root == NULL) return;
	freeTree(root->left);
	freeTree(root->right);
	free(root);
}
void inorder(Node* root){
	if(root == NULL) return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
int main(){
	Node* root = NULL;
	int values[] = {20, 10, 30, 5, 15, 25, 35};
	int n = sizeof(values) / sizeof(values[0]);
	for(int i = 0; i < n; i++){
		root = insertNode(root, values[i]);
	}
	printf("sau khi chen gt:");
	inorder(root);
	printf("\n");
	int searchValue ;
	printf("nhap gia tri can tim:");
	scanf("%d",&searchValue);
	if(searchBST(root, searchValue)){
		printf("Found.\n");
	}else{
		printf("Not Found.\n");
	}
	freeTree(root);
	return 0;
}

