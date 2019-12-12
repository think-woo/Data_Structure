//���� Ž�� Ʈ���� ���� ����
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _node{
	struct _node *left; //���� �ڽ� ���
	struct _node *right; //������ �ڽ� ���
	int data; //����ڼ��� ������
};

struct _node *create_node(int input_data); //��� ����
void delete_Tree(struct _node *root); //Ʈ�� ����
void binary_search_node(struct _node *root, int key_element); //���� Ž�� Ʈ������ �˻� ����
void insert_node(struct _node *root, int input_data); //��� �߰�
int delete_node(struct _node *root, int key_element); //�ش� ���Ҹ� ���� ��� ����
void get_max(struct _node *root, struct _node *curr); //Ʈ������ �ִ밪 ã��


int main(){

	struct _node *root = create_node(14);
	
	insert_node(root, 12);
	insert_node(root, 10);
	insert_node(root, 9);
	insert_node(root, 11);
	insert_node(root, 13);
	insert_node(root, 17);
	insert_node(root, 28);

	//�ڽ� ��尡 1���� ���
	delete_node(root, 17);
	printf("%d\n", root->right->data);

	//�ڽ� ��尡 ���� ���
	delete_node(root, 28);
	printf("%p\n", root->right);

	//�ڽ� ��尡 2���� ���
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

	//Ʈ���� ��� �ִ� ���
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
		if(root->left == NULL && root->right == NULL){ //�ڽ� ��尡 ���� ���
			return 1;
		}
		if(root->left == NULL && root->right != NULL){ //������ �ڽĸ� �ִ� ���
			root->data = root->right->data; //���� ����� �����Ϳ� ������ �ڽ� �����͸� ����
			root->left = root->right->left; //������ �ڽ��� ���� �ڽ� 
			root->right = root->right->right;//������ �ڽ��� ������ �ڽ�
			return 0;
		}
		if(root->left != NULL && root->right == NULL){//���� �ڽĸ� �ִ� ���
			root->data = root->left->data;
			root->left = root->left->left;
			root->right = root->left->right;
			return 0;
		}
		if(root->left != NULL && root->right != NULL){ //�ڽ� ��尡 ��� �ִ� ���
			get_max(root, root->left); //���� �κ� Ʈ������ ���� ū ���� �����´�
			if(delete_node(root->left, root->data) == 1){ //�ش� ���� ���� ���� �����Ѵ�
				root->left =NULL;
			}
			return 0;
		}

	}
	else if(root->data > key_element){
		if(root->left != NULL){
			if(delete_node(root->left, key_element) == 1){ //�ڽ� ��尡 ���� ���
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
			if(delete_node(root->right, key_element) == 1){ //�ڽ� ��尡 ���� ���
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