//이진 탐색 트리의 삽입 구현
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _node{
	struct _node *left; //왼쪽 자식 노드
	struct _node *right; //오른쪽 자식 노드
	int data; //사용자설정 데이터
};

struct _node *create_node(int input_data); //노드 생성
void delete_node(struct _node *node); //노드 삭제
void delete_Tree(struct _node *root); //트리 삭제
void binary_search_node(struct _node *root, int key_element); //이진 탐색 트리에서 검색 연산
void insert_node(struct _node *root, int input_data); //노드 추가

int main(){

	struct _node *root = create_node(14);
	
	insert_node(root, 10);
	insert_node(root, 12);
	insert_node(root, 13);
	insert_node(root, 17);
	insert_node(root, 28);

	binary_search_node(root, 28);
	binary_search_node(root, 27);

	printf("%d\n", root->right->right->data);

	delete_Tree(root);

	return 0;
}

struct _node *create_node(int input_data){

	struct _node *newNode = malloc(sizeof(struct _node));

	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = input_data;

	return newNode;

}

void delete_node(struct _node *node){
	free(node);
}

void delete_Tree(struct _node *root){
	if(root->left != NULL){
		delete_Tree(root->left);
	}

	if(root->right != NULL){
		delete_Tree(root->right);
	}

	delete_node(root);
}

void binary_search_node(struct _node *root, int key_element){

	if(root->data == key_element){
		printf("found\n");
	}
	else if(root->data > key_element){
		if(root->left != NULL){
			binary_search_node(root->left, key_element);
		}
		else{
			printf("not found\n");
		}
	}
	else{ //root->data < key_element
		if(root->right != NULL){
			binary_search_node(root->right, key_element);
		}
		else{
			printf("not found\n");
		}
	}
}

void insert_node(struct _node *root, int input_data){

	//트리가 비어 있는 경우
	if(root->data == -1){
		root->data = input_data;
		return;
	}

	if(root->data == input_data){
		printf("No duplicated data\n");
	}
	else if(root->data > input_data){
		if(root->left != NULL){
			insert_node(root->left, input_data);
		}
		else{
			root->left = create_node(input_data);
			
		}
	}
	else{ //root->data < input_data
		if(root->right != NULL){
			insert_node(root->right, input_data);
		}
		else{
			root->right = create_node(input_data);
		}
	}
}