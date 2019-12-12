//이진 탐색 트리의 전반적인 연산 구현
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _node{
	struct _node *lChild;
	struct _node *rChild;
	struct _node *parent;
	int key;
};

struct _node* treeSearch(struct _node *node, int key); //트리 내에서 key값을 탐색하고, 해당 key값을 가진 노드 혹은 해당 key값이 들어갈 외부노드(삽입연산에서 사용) 반호나

int findElement(struct _node *root, int key); //key값을 넣어 element를 반환한다 (다만, 현재 구현상 key = element라 간주)
void insertItem(struct _node *root, int key); //key값을 가지는 새 노드를 현재 트리에 삽입
int removeElement(struct _node *root, int key); //해당 key값을 가진 노드를 삭제하고, element를 반환 (다만, 현재 구현상 key = element라 간주)

struct _node* createNode(); //external노드 생성
void expandExternal(struct _node *node); //해당 노드의 external노드 설정 >> 해당 노드를 internal노드로 만들어준다


struct _node* reduceExternal(struct _node *childNode); //자식노드를 인자로 넣어 해당 부모노드까지 삭제, 그리고 자식노드의 형제노드 반환
struct _node* sibling(struct _node *node); //해당 노드의 형제노드를 반환

struct _node* inOrderSucc(struct _node *node); //해당 노드의 중위순회 후계자를 반환

void printTreePreOrder(struct _node *root); //전위순회로 트리 출력

int isExternal(struct _node *node); //해당 노드가 외부 노드인지 판별
int isInternal(struct _node *node); //해당 노드가 내부 노드인지 판별


int main()
{
	int key; //입력 key
	char command; //명령어

	struct _node *root = createNode();

	scanf("%c", &command);

	while(command != 'q'){

		if(command == 'i' || command == 's' || command == 'd'){
			scanf("%d", &key);
			if(command == 'i'){ //삽입
				insertItem(root, key);
			}
			if(command == 's'){ //키 탐색
				findElement(root, key);
			}
			if(command == 'd'){ //키 삭제
				removeElement(root, key);
			}
		}
		else{ // command == 'p' || command == 'q'
			if(command == 'p'){//전위순회 탐색
				printTreePreOrder(root);
				printf("\n");
			}
		}

		scanf("%c", &command);
	}
	
    return 0;
}

struct _node* treeSearch(struct _node *node, int key){
	
	if(isExternal(node)){
		return node;
	}

	if(node->key == key){
		return node;
	}
	else if(node->key > key){
		return treeSearch(node->lChild, key);
	}
	else{ //node->key < key
		return treeSearch(node->rChild, key);
	}

}

int findElement(struct _node *root, int key){

	struct _node *findNode = treeSearch(root, key);

	if(isExternal(findNode)){
		printf("X\n");
		return;
	}
	else{ 
		printf("%d\n", key);
		return key;
	}
}

void insertItem(struct _node *root, int key){

	struct _node *findNode = treeSearch(root, key);

	if(isInternal(findNode)){ 
		return;
	}
	else{
		findNode->key = key;
		expandExternal(findNode);
		return;
	}
}

struct _node* createNode(){
	struct _node *newNode = malloc(sizeof(struct _node));

	newNode->lChild = NULL;
	newNode->rChild = NULL;
	newNode->parent = NULL;
	newNode->key = NULL;

	return newNode;
}

void expandExternal(struct _node *node){
	//해당 노드와 새로 생성한 external노드 연결
	node->lChild = createNode();
	node->rChild = createNode();

	//external노드의 parent노드 설정
	node->lChild->parent = node;
	node->rChild->parent = node;
}

int removeElement(struct _node *root, int key){

	struct _node *findNode = treeSearch(root, key);
	struct _node *findNodeChild; //찾은 노드의 자식노드
	struct _node *inOrderSuccNode; //중위순회 후계자

	if(isExternal(findNode)){
		printf("X\n");
		return;
	}

	findNodeChild = findNode->lChild;

	if(!isExternal(findNodeChild)){
		findNodeChild = findNode->rChild;
	}
	
	if(isExternal(findNodeChild)){
		reduceExternal(findNodeChild);
	}
	else{
		inOrderSuccNode = inOrderSucc(findNode);
		findNodeChild = inOrderSuccNode->lChild;
		findNode->key = inOrderSuccNode->key;
		reduceExternal(findNodeChild);
	}

	printf("%d\n", key);

	return key;
}

struct _node* reduceExternal(struct _node *childNode){
	struct _node *parentNode = childNode->parent; //부모노드
	struct _node *siblingNode = sibling(childNode); //형제노드
	struct _node *parentParentNode; //부모노드의 부모노드

	if(parentNode->parent == NULL){ //parentNode가 root노드인 경우 >> root를 새롭게 지정
		//root를 해제하면 find, insert, remove에서 오류가 발생한다 >>> 형제노드의 정보를 루트로 복사하기
		parentNode->key = siblingNode->key;
		parentNode->rChild = siblingNode->rChild;
		parentNode->lChild = siblingNode->lChild;

		free(childNode);
		free(siblingNode);

		return parentNode;
	}
	else{ //parentNode가 root노드가 아닌 경우
		parentParentNode = parentNode->parent;
		siblingNode->parent = parentParentNode;
		if(parentNode == parentParentNode->lChild){
			parentParentNode->lChild = siblingNode;
		}
		else{ //parentNode == parentParentNode->rChild
			parentParentNode->rChild = siblingNode;
		}

		return siblingNode;
	}	
}

struct _node* sibling(struct _node *node){
	
	if(node->parent == NULL){ //node가 root노드인 경우
		return; //하지만 해당 연산을 사용하는 노드는 현재 external노드 밖에 없으므로 해당 상황은 발생하지 않는다
	}
	
	if(node->parent->lChild == node){
		return node->parent->rChild;
	}
	else{ //node->parent->rChild == node
		return node->parent->lChild;
	}
}

struct _node* inOrderSucc(struct _node *node){
	node = node->rChild;
	
	if(isExternal(node)){ //바로 오른쪽 자식 노드가 외부노드이다 >> 중위순회 후계자가 없는 경우
		return; //하지만 현재 연산에서는 internal노드 2개를 자식으로 가지는 노드가 들어오는 상황이므로 발생하지 않는다
	}
	
	while(isInternal(node->lChild)){ //가장 왼쪽으로 이동
		node = node->lChild;
	}
	return node;
}

void printTreePreOrder(struct _node *root){

	printf(" %d", root->key);

	if(isInternal(root->lChild)){
		printTreePreOrder(root->lChild);
	}
	
	if(isInternal(root->rChild)){
		printTreePreOrder(root->rChild);
	}
}

int isExternal(struct _node *node){
	if(node->lChild == NULL && node->rChild ==NULL){
		return 1;
	}
	else{ //node->lChild != NULL || node->rChild != NULL
		return 0;
	}
}

int isInternal(struct _node *node){
	if(node->lChild != NULL || node->rChild != NULL){
		return 1;
	}
	else{ //node->lChild == NULL && node->rChild ==NULL
		return 0;
	}
}