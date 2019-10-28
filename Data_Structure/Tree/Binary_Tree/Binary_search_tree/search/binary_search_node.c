//���� Ž�� Ʈ���� Ž�� ����
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _node{
	struct _node *left; //���� �ڽ� ���
	struct _node *right; //������ �ڽ� ���
	int data; //����ڼ��� ������
};

struct _node *create_node(int input_data); //��� ����
void delete_node(struct _node *node); //��� ����
void delete_Tree(struct _node *root); //Ʈ�� ����
void binary_search_node(struct _node *root, int key_element); //���� Ž�� Ʈ������ �˻� ����

int main(){

	struct _node *root = create_node(14);
	struct _node *Node[5];
	
	Node[0] = create_node(10);
	Node[1] = create_node(12);
	Node[2] = create_node(13);
	Node[3] = create_node(17);
	Node[4] = create_node(28);

	root->left = Node[0];
	root->right = Node[3];
	Node[0]->left = Node[1];
	Node[0]->right = Node[2];
	Node[3]->right = Node[4];

	binary_search_node(root, 28);
	binary_search_node(root, 27);

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