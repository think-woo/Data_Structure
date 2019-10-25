//���� �ڽ� ������ ���� Ʈ�� ����
#include <stdio.h>
#include <stdlib.h> //malloc(), free();

struct LCRSNode {
	struct LCRSNode *leftChild; //���� �ڽ�
	struct LCRSNode *rigthSibling; //������ ����
	int data; //����� ���� ������
};

struct LCRSNode* createNode(int inputData); //��� ����
void appendNode(struct LCRSNode *parent, struct LCRSNode *child); //�θ� ��忡 �ڽ� ��� �߰�
void printTree(struct LCRSNode *node, int depth); //�ش� ������ ������ ������ ���
void deleteNode(struct LCRSNode *node); //�ش� ��� ����
void deleteTree(struct LCRSNode *root); //Ʈ�� ����

int main(){

	struct LCRSNode *parentNode[5];
	struct LCRSNode *siblingNode[3];
	int i, j;

	//�θ� ��� ����
	for(i=0, j=0; i<sizeof(parentNode)/sizeof(struct LCRSNode*); i++, j+=10){
		parentNode[i] = createNode(j);
	}

	//���� ��� ����
	for(i=0, j=100; i<sizeof(siblingNode)/sizeof(struct LCRSNode*); i++, j+=10){
		siblingNode[i] = createNode(j);
	}

	//�θ� ��� ����
	for(i=0; i<sizeof(parentNode)/sizeof(struct LCRSNode*) - 1; i++){
		appendNode(parentNode[i], parentNode[i+1]);
	}

	//���� ��� ����
	for(i=0; i<sizeof(siblingNode)/sizeof(struct LCRSNode*); i++){
		appendNode(parentNode[0], siblingNode[i]);
	}

	//���
	printTree(parentNode[0], 0);

	//Ʈ�� ����
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

	struct LCRSNode *curr; //��ȯ���

	if(parent->leftChild == NULL){ //�θ��忡 �ڽ��� ���� ���
		parent->leftChild = child;
	}
	else{ //�θ��忡 �ڽ��� �ִ� ��� >> ������ �θ� ���� ���� ������ �ڽĿ� ��带 �����Ѵ�
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

	if(node->rigthSibling != NULL){ //���� ���� ���
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