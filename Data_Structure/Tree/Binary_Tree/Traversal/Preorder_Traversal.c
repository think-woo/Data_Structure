//전위 우선 탐색 구현
#include <stdio.h>
#include <stdlib.h> //malloc(), free();

struct _node {
	struct _node *leftNode, *rightNode; //왼쪽, 오른쪽 노드
	int data; //사용자지정 데이터
};

struct _node* create_node(int input); //데이터를 사진 노드 생성
void append_node(struct _node *parent, struct _node *child); //해당 부모노드에 자식노드 추가
void delete_node(struct _node *node); //헤당 노드 삭제
void delete_Tree(struct _node *root); //해당 트리 삭제
void Preorder_Traversal(struct _node *root); //전위 우선 탐색

int main(){

	struct _node *Node[9];
	int i, j;

	for(i=0, j=10; i<sizeof(Node)/sizeof(struct _node*); i++, j+=10){
		Node[i] = create_node(j);
	}

	Node[0]->leftNode = Node[1];
	Node[0]->rightNode = Node[2];
	Node[1]->leftNode = Node[3];
	Node[1]->rightNode = Node[4];
	Node[2]->leftNode = Node[5];
	Node[2]->rightNode = Node[6];
	Node[3]->leftNode = Node[7];
	Node[3]->rightNode = Node[8];

	Preorder_Traversal(Node[0]);

	return 0;
	
}

struct _node* create_node(int input){

	struct _node *newNode = malloc(sizeof(struct _node));

	newNode->leftNode = NULL;
	newNode->rightNode =NULL;
	newNode->data = input;

	return newNode;
}


void delete_node(struct _node *node){
	free(node);
}

void delete_Tree(struct _node *root){

	if(root->leftNode != NULL){
		delete_Tree(root->leftNode);
	}

	if(root->rightNode != NULL){
		delete_Tree(root->rightNode);
	}

	root->leftNode = NULL;
	root->rightNode = NULL;

	delete_node(root);
}

void Preorder_Traversal(struct _node *root){

	if(root){
		printf("%d ", root->data);
		Preorder_Traversal(root->leftNode);
		Preorder_Traversal(root->rightNode);
	}
}