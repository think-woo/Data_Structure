//���� Ž�� Ʈ���� degree�� ���ϱ�
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _node{
	struct _node *left; //���� �ڽ� ���
	struct _node *right; //������ �ڽ� ���
	int data; //����ڼ��� ������
};

struct _node *create_node(int input_data); //��� ����
void delete_Tree(struct _node *root); //Ʈ�� ����
void insert_node(struct _node *root, int input_data); //��� �߰�
void find_degree(struct _node *root, int *treeDegree); //Ʈ���� degree ���


int main(){

	int degree = 0; //degree�� 0���� �ʱ�ȭ
	int *treeDegree = &degree;

	struct _node *root = create_node(1);

	insert_node(root, 2);
	insert_node(root, 5);
	insert_node(root, 6);
	//�־��� ����Ʈ�� ����

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

void find_degree(struct _node *root, int *treeDegree){

	//degree ���
	if(*treeDegree != 2 && root->left != NULL && root->right == NULL){ //���� ��常 NULL�� ���
		*treeDegree = 1;
	}
	if(*treeDegree != 2 && root->left == NULL && root->right != NULL){//������ ��常 NULL�� ���
		*treeDegree = 1;
	}
	if(root->left != NULL && root->right != NULL){ //�ڽ� ��尡 ���� �ִ� ���
		*treeDegree = 2;
	}

	//Ʈ�� �̵�
	if(root->left != NULL){
		find_degree(root->left, treeDegree);
	}
	if(root->right != NULL){
		find_degree(root->right, treeDegree);
	}

}