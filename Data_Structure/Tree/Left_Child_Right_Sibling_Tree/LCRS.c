//왼쪽 자식 오른쪽 형제 트리 구현
#include <stdio.h>
#include <stdlib.h> //malloc(), free();

struct LCRSNode {
	struct LCRSNode *leftChild; //왼쪽 자식
	struct LCRSNode *rigthSibling; //오른쪽 형제
	int data; //사용자 정의 데이터
};

struct LCRSNode* createNode(int inputData); //노드 생성
void appendNode(struct LCRSNode *parent, struct LCRSNode *child); //부모 노드에 자식 노드 추가
void printTree(struct LCRSNode *node, int depth); //해당 깊이의 노드부터 끝까지 출력
void deleteNode(struct LCRSNode *node); //해당 노드 삭제
void deleteTree(struct LCRSNode *root); //트리 삭제

int main(){

	struct LCRSNode *parentNode[5];
	struct LCRSNode *siblingNode[3];
	int i, j;

	//부모 노드 생성
	for(i=0, j=0; i<sizeof(parentNode)/sizeof(struct LCRSNode*); i++, j+=10){
		parentNode[i] = createNode(j);
	}

	//형제 노드 생성
	for(i=0, j=100; i<sizeof(siblingNode)/sizeof(struct LCRSNode*); i++, j+=10){
		siblingNode[i] = createNode(j);
	}

	//부모 노드 연결
	for(i=0; i<sizeof(parentNode)/sizeof(struct LCRSNode*) - 1; i++){
		appendNode(parentNode[i], parentNode[i+1]);
	}

	//형제 노드 연결
	for(i=0; i<sizeof(siblingNode)/sizeof(struct LCRSNode*); i++){
		appendNode(parentNode[0], siblingNode[i]);
	}

	//출력
	printTree(parentNode[0], 0);

	//트리 삭제
	deleteTree(parentNode[0]);

	return 0;
}

struct LCRSNode* createNode(int inputData){

	struct LCRSNode *newNode = malloc(sizeof(struct LCRSNode));
	newNode->leftChild = NULL;
	newNode->rigthSibling = NULL;
	newNode->data = inputData;

	return newNode;
}

void appendNode(struct LCRSNode *parent, struct LCRSNode *child){

	struct LCRSNode *curr; //순환노드

	if(parent->leftChild == NULL){ //부모노드에 자식이 없는 경우
		parent->leftChild = child;
	}
	else{ //부모노드에 자식이 있는 경우 >> 동일한 부모를 가진 가장 오른쪽 자식에 노드를 연결한다
		curr = parent->leftChild;

		while(curr->rigthSibling != NULL){
			curr = curr->rigthSibling;
		}
		curr->rigthSibling = child;
	}

}


void printTree(struct LCRSNode *node, int depth){

	int i = 0;
	for(i=0; i<depth; i++){
		printf(" ");
	}
	printf("%d\n", node->data);

	if(node->rigthSibling != NULL){ //형제 먼저 출력
		printTree(node->rigthSibling, depth);
	}

	if(node->leftChild != NULL){
		printTree(node->leftChild, depth+1);
	}
	
}

void deleteNode(struct LCRSNode *node){
	free(node);
}

void deleteTree(struct LCRSNode *root){

	if(root->rigthSibling != NULL){
		deleteTree(root->rigthSibling);
	}

	if(root->leftChild != NULL){
		deleteTree(root->leftChild);
	}

	root->leftChild = NULL;
	root->rigthSibling = NULL;

	deleteNode(root);
}