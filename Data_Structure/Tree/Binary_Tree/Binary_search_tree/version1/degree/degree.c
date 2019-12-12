//이진 탐색 트리의 degree를 구하기
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _node{
	struct _node *left; //왼쪽 자식 노드
	struct _node *right; //오른쪽 자식 노드
	int data; //사용자설정 데이터
};

struct _node *create_node(int input_data); //노드 생성
void delete_Tree(struct _node *root); //트리 삭제
void insert_node(struct _node *root, int input_data); //노드 추가
void find_degree(struct _node *root, int *treeDegree); //트리의 degree 계산


int main(){

	int degree = 0; //degree를 0으로 초기화
	int *treeDegree = &degree;

	struct _node *root = create_node(1);

	insert_node(root, 2);
	insert_node(root, 5);
	insert_node(root, 6);
	//최악의 이진트리 구현

	find_degree(root, treeDegree);

	printf("%d\n", *treeDegree);

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

void find_degree(struct _node *root, int *treeDegree){

	//degree 계산
	if(*treeDegree != 2 && root->left != NULL && root->right == NULL){ //왼쪽 노드만 NULL인 경우
		*treeDegree = 1;
	}
	if(*treeDegree != 2 && root->left == NULL && root->right != NULL){//오른쪽 노드만 NULL인 경우
		*treeDegree = 1;
	}
	if(root->left != NULL && root->right != NULL){ //자식 노드가 전부 있는 경우
		*treeDegree = 2;
	}

	//트리 이동
	if(root->left != NULL){
		find_degree(root->left, treeDegree);
	}
	if(root->right != NULL){
		find_degree(root->right, treeDegree);
	}

}