//�ؽ����̺��� ���� �ּҹ� ����
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _hashTable {
	int key;
	int isEmpty; //0 == �������, 1 == Ȱ��, -1 == ��Ȱ��
};

//��������
struct _hashTable* H;
int M; //hastTableSize;
int N; //���� ����
int q; //�����ؽ̿��� ����� �Ҽ�

//�Լ�
int hash(int key); //�ؽ��Լ�
int hash2(int key); //�����ؽ̿��� ����� �ؽ��Լ�
void initBucketArray(); //�ؽ����̺� �ʱ�ȭ
int getNextBucket(int v, int i, int key); //���� bucket�ּҸ� ��ȯ
void insertElement(int key); //Ű ���� �� ������ bucket�ּҸ� ���
int findElement(int key); //Ű Ž�� �� ���� ��ȯ //����Ǯ�̻� ������ -1, ������ bucket�ּҸ� ���
void printHashTable(); //�ؽ����̺� ���

int main() {

	//hastTableSize, ���� ����, �����ؽ� �Ҽ� �Է�
	scanf("%d %d %d", &M, &N, &q);

	int key; //Ű��
	char command; //��ɾ�

	//�ʱ�ȭ
	initBucketArray();

	scanf("%c", &command);
	while (1) {
		if (command == 'i' || command == 's') {
			scanf("%d", &key);
			if (command == 'i') {
				insertElement(key);
			}
			if (command == 's') {
				findElement(key);
			}
		}
		else { //command != 'i' || command != 's'
			if (command == 'p') {
				printHashTable();
			}
			if (command == 'e') {
				printHashTable();
				break;
			}
		}
		scanf("%c", &command);

	}

	return 0;
}

int hash(int key) {
	return key % M;
}

int hash2(int key)
{
	return q - (key % q);
}

void initBucketArray() {

	H = (struct _hashTable*)malloc(sizeof(struct _hashTable));

	for (int i = 0; i < M; i++) {
		H[i].key = 0;
		H[i].isEmpty = 0;
	}
}
/*
//���������
int getNextBucket(int v, int i)
{
	return (v+i)%M;
}

//2�������
int getNextBucket(int v, int i)
{
	return (v + i*i) % M;
}
*/
//�����ؽ�
int getNextBucket(int v, int i, int key)
{
	return (v + i * hash2(key)) % M;
}

void insertElement(int key) {
	
	//1.
	int v = hash(key);
	
	//2.
	int b;//bucketIndex

	for (int i = 0; i < M; i++) {
		b = getNextBucket(v, i, key); //bucketIndex

		if (H[b].isEmpty == 1) { //bucket�� Ű���� �ִ� ����
			printf("C");
		}
		else { //bucket�� Ű���� �ִ��� ��Ȱ���Ǿ��ְų�, ���»���
			H[b].key = key;
			H[b].isEmpty = 1;
			printf("%d\n", b);
			return;
		}
	}
}

int findElement(int key)
{
	//1.
	int v = hash(key);

	//2.
	int b;//bucketIndex

	for (int i = 0; i < M; i++) {
		b = getNextBucket(v, i, key); //bucketIndex

		if (H[b].isEmpty == 1) { //bucket�� Ű���� �ִ� ����(Ȱ��)
			if (H[b].key == key) { //Ž���� Ű���� �ִ� ���
				printf("%d %d\n", b, key);
				return;
			}
		}
	}

	//3. Ű���� ���� ���
	printf("-1\n");
}

void printHashTable() {

	for (int i = 0; i < M; i++) {
		printf(" %d", H[i].key);
	}

	printf("\n");

	return;
}