//���� Ž�� Ʈ���� width ���ϱ� (���� �Ÿ��� �� �� ��� ������ �Ÿ�)
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
void findDirectionAndInsertNode(struct _node *root, int input_data, int *leftTreeDepth, int *righTreetDeppth, int *treeCount);//���� Ȥ�� ������ �κ� Ʈ���� depth�� ���Ѵ�

int main(){

	int leftDepth = 1; //�⺻ ���̴� 1
	int *leftTreeDepth = &leftDepth;

	int rightDeppth = 1;
	int *righTreetDeppth = &rightDeppth;

	int count = 1;
	int *treeCount = &count;

	struct _node *root = create_node(17);

	findDirectionAndInsertNode(root, 11, leftTreeDepth, righTreetDeppth, treeCount);
	findDirectionAndInsertNode(root, 6, leftTreeDepth, righTreetDeppth, treeCount);
	findDirectionAndInsertNode(root, 15, leftTreeDepth, righTreetDeppth, treeCount);
	findDirectionAndInsertNode(root, 19, leftTreeDepth, righTreetDeppth, treeCount);
	findDirectionAndInsertNode(root, 21, leftTreeDepth, righTreetDeppth, treeCount);
	findDirectionAndInsertNode(root, 22, leftTreeDepth, righTreetDeppth, treeCount);
	//���� ����Ʈ�� ����

	printf("%d\n", (*leftTreeDepth-1) + (*righTreetDeppth-1));

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

void findDirectionAndInsertNode(struct _node *root, int input_data, int *leftTreeDepth, int *rightTreeDepth, int *treeCount){

	if(root->data > input_data){
		insert_node(root, input_data, leftTreeDepth, treeCount);
	}
	else{ //root->data < input_data
		insert_node(root, input_data, rightTreeDepth, treeCount);
	}
}