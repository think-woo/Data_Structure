//이진 탐색 트리의 제거 구현
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _node{
	struct _node *left; //왼쪽 자식 노드
	struct _node *right; //오른쪽 자식 노드
	int data; //사용자설정 데이터
};

struct _node *create_node(int input_data); //노드 생성
void delete_Tree(struct _node *root); //트리 삭제
void binary_search_node(struct _node *root, int key_element); //이진 탐색 트리에서 검색 연산
void insert_node(struct _node *root, int input_data); //노드 추가
int delete_node(struct _node *root, int key_element); //해당 원소를 가진 노드 삭제
void get_max(struct _node *root, struct _node *curr); //트리에서 최대값 찾기


int main(){

	struct _node *root = create_node(14);
	
	insert_node(root, 12);
	insert_node(root, 10);
	insert_node(root, 9);
	insert_node(root, 11);
	insert_node(root, 13);
	insert_node(root, 17);
	insert_node(root, 28);

	//자식 노드가 1개인 경우
	delete_node(root, 17);
	printf("%d\n", root->right->data);

	//자식 노드가 없는 경우
	delete_node(root, 28);
	printf("%p\n", root->right);

	//자식 노드가 2개인 경우
	delete_node(root, 12);
	printf("%d\n", root->left->data);
	printf("%d\n", root->left->left->data);
	printf("%p\n", root->left->left->right);
	printf("%d\n", root->left->left->left->data);
	printf("%d\n", root->left->right->data);

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

void delete_Tree(struct _node *root){
	if(root->left != NULL){
		delete_Tree(root->left);
	}

	if(root->right != NULL){
		delete_Tree(root->right);
	}

	free(root);
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

int delete_node(struct _node *root, int key_element){

	if(root->data == key_element){
		if(root->left == NULL && root->right == NULL){ //자식 노드가 없는 경우
			return 1;
		}
		if(root->left == NULL && root->right != NULL){ //오른쪽 자식만 있는 경우
			root->data = root->right->data; //기존 노드의 데이터에 오른쪽 자식 데이터를 삽입
			root->left = root->right->left; //오른쪽 자식의 왼쪽 자식 
			root->right = root->right->right;//오른쪽 자식의 오른쪽 자식
			return 0;
		}
		if(root->left != NULL && root->right == NULL){//왼쪽 자식만 있는 경우
			root->data = root->left->data;
			root->left = root->left->left;
			root->right = root->left->right;
			return 0;
		}
		if(root->left != NULL && root->right != NULL){ //자식 노드가 모두 있는 경우
			get_max(root, root->left); //왼쪽 부분 트리에서 가장 큰 값을 가져온다
			if(delete_node(root->left, root->data) == 1){ //해당 값을 가진 노드는 삭제한다
				root->left =NULL;
			}
			return 0;
		}

	}
	else if(root->data > key_element){
		if(root->left != NULL){
			if(delete_node(root->left, key_element) == 1){ //자식 노드가 없는 경우
				root->left = NULL;
			}
		}
		else{
			printf("not found\n");
		}
		return 0;
	}
	else{ //root->data < key_element
		if(root->right != NULL){
			if(delete_node(root->right, key_element) == 1){ //자식 노드가 없는 경우
				root->right = NULL;
			}
		}
		else{
			printf("not found\n");
		}
		return 0;
	}
}

void get_max(struct _node *root, struct _node *curr){

	if(curr->left != NULL){
		get_max(root, curr->left);
	}

	root->data = curr->data;

	if(curr->right != NULL){
		get_max(root, curr->right);
	}
}