//���� Ž�� Ʈ���� depth�� ���ϱ�
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _node{
	struct _node *left; //���� �ڽ� ���
	struct _node *right; //������ �ڽ� ���
	int data; //����ڼ��� ������
};

struct _node *create_node(int input_data); //��� ����
void delete_Tree(struct _node *root); //Ʈ�� ����
void insert_node(struct _node *root, int input_data, int *treeDepth, int *treeCount); //��� �߰�


int main(){

	int depth = 1; //�⺻ ���̴� 1
	int *treeDepth = &depth;

	int count = 1;
	int *treeCount = &count;

	struct _node *root = create_node(17);

	insert_node(root, 11, treeDepth, treeCount);
	insert_node(root, 6, treeDepth, treeCount);
	insert_node(root, 15, treeDepth, treeCount);
	insert_node(root, 19, treeDepth, treeCount);
	insert_node(root, 21, treeDepth, treeCount);
	insert_node(root, 22, treeDepth, treeCount);
	//���� ����Ʈ�� ����

	printf("%d\n", *treeDepth);

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

void insert_node(struct _node *root, int input_data, int *treeDepth, int *treeCount){

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
			*treeCount+=1;
			insert_node(root->left, input_data, treeDepth, treeCount);
		}
		else{
			*treeCount+=1;
			root->left = create_node(input_data);
			if(*treeCount > *treeDepth){
				*treeDepth = *treeCount;
			}
			*treeCount=1; //count�ʱ�ȭ
		}
	}
	else{ //root->data < input_data
		if(root->right != NULL){
			*treeCount+=1;
			insert_node(root->right, input_data, treeDepth, treeCount);
		}
		else{
			*treeCount+=1;
			root->right = create_node(input_data);
			if(*treeCount > *treeDepth){
				*treeDepth = *treeCount;
			}
			*treeCount=1; //count�ʱ�ȭ
		}
	}
}
