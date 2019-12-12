//���� Ž�� Ʈ���� �������� ���� ����
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _node{
	struct _node *lChild;
	struct _node *rChild;
	struct _node *parent;
	int key;
};

struct _node* treeSearch(struct _node *node, int key); //Ʈ�� ������ key���� Ž���ϰ�, �ش� key���� ���� ��� Ȥ�� �ش� key���� �� �ܺγ��(���Կ��꿡�� ���) ��ȣ��

int findElement(struct _node *root, int key); //key���� �־� element�� ��ȯ�Ѵ� (�ٸ�, ���� ������ key = element�� ����)
void insertItem(struct _node *root, int key); //key���� ������ �� ��带 ���� Ʈ���� ����
int removeElement(struct _node *root, int key); //�ش� key���� ���� ��带 �����ϰ�, element�� ��ȯ (�ٸ�, ���� ������ key = element�� ����)

struct _node* createNode(); //external��� ����
void expandExternal(struct _node *node); //�ش� ����� external��� ���� >> �ش� ��带 internal���� ������ش�


struct _node* reduceExternal(struct _node *childNode); //�ڽĳ�带 ���ڷ� �־� �ش� �θ������ ����, �׸��� �ڽĳ���� ������� ��ȯ
struct _node* sibling(struct _node *node); //�ش� ����� ������带 ��ȯ

struct _node* inOrderSucc(struct _node *node); //�ش� ����� ������ȸ �İ��ڸ� ��ȯ

void printTreePreOrder(struct _node *root); //������ȸ�� Ʈ�� ���

int isExternal(struct _node *node); //�ش� ��尡 �ܺ� ������� �Ǻ�
int isInternal(struct _node *node); //�ش� ��尡 ���� ������� �Ǻ�


int main()
{
	int key; //�Է� key
	char command; //��ɾ�

	struct _node *root = createNode();

	scanf("%c", &command);

	while(command != 'q'){

		if(command == 'i' || command == 's' || command == 'd'){
			scanf("%d", &key);
			if(command == 'i'){ //����
				insertItem(root, key);
			}
			if(command == 's'){ //Ű Ž��
				findElement(root, key);
			}
			if(command == 'd'){ //Ű ����
				removeElement(root, key);
			}
		}
		else{ // command == 'p' || command == 'q'
			if(command == 'p'){//������ȸ Ž��
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
	//�ش� ���� ���� ������ external��� ����
	node->lChild = createNode();
	node->rChild = createNode();

	//external����� parent��� ����
	node->lChild->parent = node;
	node->rChild->parent = node;
}

int removeElement(struct _node *root, int key){

	struct _node *findNode = treeSearch(root, key);
	struct _node *findNodeChild; //ã�� ����� �ڽĳ��
	struct _node *inOrderSuccNode; //������ȸ �İ���

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
	struct _node *parentNode = childNode->parent; //�θ���
	struct _node *siblingNode = sibling(childNode); //�������
	struct _node *parentParentNode; //�θ����� �θ���

	if(parentNode->parent == NULL){ //parentNode�� root����� ��� >> root�� ���Ӱ� ����
		//root�� �����ϸ� find, insert, remove���� ������ �߻��Ѵ� >>> ��������� ������ ��Ʈ�� �����ϱ�
		parentNode->key = siblingNode->key;
		parentNode->rChild = siblingNode->rChild;
		parentNode->lChild = siblingNode->lChild;

		free(childNode);
		free(siblingNode);

		return parentNode;
	}
	else{ //parentNode�� root��尡 �ƴ� ���
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
	
	if(node->parent == NULL){ //node�� root����� ���
		return; //������ �ش� ������ ����ϴ� ���� ���� external��� �ۿ� �����Ƿ� �ش� ��Ȳ�� �߻����� �ʴ´�
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
	
	if(isExternal(node)){ //�ٷ� ������ �ڽ� ��尡 �ܺγ���̴� >> ������ȸ �İ��ڰ� ���� ���
		return; //������ ���� ���꿡���� internal��� 2���� �ڽ����� ������ ��尡 ������ ��Ȳ�̹Ƿ� �߻����� �ʴ´�
	}
	
	while(isInternal(node->lChild)){ //���� �������� �̵�
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