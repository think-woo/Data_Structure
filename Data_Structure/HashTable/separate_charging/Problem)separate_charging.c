#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

//�ؽ����̺�
struct _hashTable {
	int key;
	struct _hashTable* next;
};

//��������
int M; //hastTableSize;
struct _hashTable* H;

//�Լ�
int hash(int key); //�ؽ��Լ�
void initBucketArray(); //�ؽ����̺� �ʱ�ȭ
void insertElement(int key); //Ű ����
int findElement(int key); //Ű Ž�� �� ���� ��ȯ //����Ǯ�̻� ������ 0, ������ 1���� �����ϴ� ���� ��ȯ
int removeElement(int key); //Ű ���� �� ���� ��ȯ //����Ǯ�̻� ������ 0, ������ 1���� �����ϴ� ���� ��ȯ
void printHashTable(); //�ؽ����̺� ���

int main() {

	//hastTableSize �Է�
	scanf("%d\n", &M);

	int key; //Ű��
	char command; //��ɾ�

	//�ʱ�ȭ
	initBucketArray();

	scanf("%c", &command);
	while (command != 'e') {
		if (command != 'p') {
			scanf("%d", &key);
			if (command == 'i') {
				insertElement(key);
			}
			if (command == 's') {
				printf("%d\n", findElement(key));
			}
			if (command == 'd') {
				printf("%d\n", removeElement(key));
			}
		}

		if (command == 'p') {
			printHashTable();
		}

		scanf("%c", &command);

	}

	return 0;
}

int hash(int key) {
	return key % M;
}

void initBucketArray() {

	int i;

	H = (struct _hashTable*)malloc(sizeof(struct _hashTable) * M);

	for (i = 0; i < M; i++) {
		H[i].key = -1;
		H[i].next = NULL;
	}
}

void insertElement(int key) {

	//1.
	int v = hash(key);

	//2.
	if (H[v].next == NULL) {
		H[v].next = (struct _hashTable*)malloc(sizeof(struct _hashTable));
		H[v].next->key = key;
		H[v].next->next = NULL;
	}
	else { //H[v].next != NULL

		struct _hashTable* newNode = (struct _hashTable*)malloc(sizeof(struct _hashTable));
		newNode->next = H[v].next;
		newNode->key = key;

		H[v].next = newNode;
	}

	return;

}

int findElement(int key)
{
	//1.
	int v = hash(key);

	//2
	struct _hashTable* curr = H[v].next; //��ȸ
	int count = 1; //��� ����
	while (curr != NULL) {
		if (curr->key == key) {
			return count;
		}
		count++;
		curr = curr->next;
	}

	//3. Ž���ϴ� Ű���� ���� ���
	return 0;
}

int removeElement(int key)
{
	//1.
	int v = hash(key);

	//2.
	struct _hashTable* curr = H[v].next; //��ȸ
	struct _hashTable* previous = &H[v];
	int count = 1; //��� ����
	while (curr != NULL) {
		if (curr->key == key) {
			if (curr->next != NULL) { //������ ��尡 �������� �ƴ� ���
				previous->next = curr->next;
			}
			else { //curr->next == NULL //������ ��尡 �������� ���
				previous->next = NULL;
			}
			free(curr);
			return count;
		}

		count++;
		previous = curr;
		curr = curr->next;
	}

	//3. ������ ��尡 ���� ���
	return 0;
}

void printHashTable() {
	int i;

	for (i = 0; i < M; i++) {

		struct _hashTable* curr = H[i].next;; //��ȸ

		while (curr != NULL) {
			printf(" %d", curr->key);
			curr = curr->next;
		}
	}

	printf("\n");

	return;
}