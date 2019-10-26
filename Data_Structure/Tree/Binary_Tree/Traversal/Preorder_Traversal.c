//���� �켱 Ž�� ����
#include <stdio.h>
#include <stdlib.h> //malloc(), free();

struct _node {
	struct _node *leftNode, *rightNode; //����, ������ ���
	int data; //��������� ������
};

struct _node* create_node(int input); //�����͸� ���� ��� ����
void append_node(struct _node *parent, struct _node *child); //�ش� �θ��忡 �ڽĳ�� �߰�
void delete_node(struct _node *node); //��� ��� ����
void delete_Tree(struct _node *root); //�ش� Ʈ�� ����
void Preorder_Traversal(struct _node *root); //���� �켱 Ž��

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