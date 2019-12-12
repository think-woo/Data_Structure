#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

//해시테이블
struct _hashTable {
	int key;
	struct _hashTable* next;
};

//전역변수
int M; //hastTableSize;
struct _hashTable* H;

//함수
int hash(int key); //해시함수
void initBucketArray(); //해시테이블 초기화
void insertElement(int key); //키 삽입
int findElement(int key); //키 탐색 및 원소 반환 //문제풀이상 없으면 0, 있으면 1부터 시작하는 순위 반환
int removeElement(int key); //키 삭제 및 원소 반환 //문제풀이상 없으면 0, 있으면 1부터 시작하는 순위 반환
void printHashTable(); //해시테이블 출력

int main() {

	//hastTableSize 입력
	scanf("%d\n", &M);

	int key; //키값
	char command; //명령어

	//초기화
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
	struct _hashTable* curr = H[v].next; //순회
	int count = 1; //노드 순위
	while (curr != NULL) {
		if (curr->key == key) {
			return count;
		}
		count++;
		curr = curr->next;
	}

	//3. 탐색하는 키값이 없는 경우
	return 0;
}

int removeElement(int key)
{
	//1.
	int v = hash(key);

	//2.
	struct _hashTable* curr = H[v].next; //순회
	struct _hashTable* previous = &H[v];
	int count = 1; //노드 순위
	while (curr != NULL) {
		if (curr->key == key) {
			if (curr->next != NULL) { //삭제할 노드가 마지막이 아닌 경우
				previous->next = curr->next;
			}
			else { //curr->next == NULL //삭제할 노드가 마지막인 경우
				previous->next = NULL;
			}
			free(curr);
			return count;
		}

		count++;
		previous = curr;
		curr = curr->next;
	}

	//3. 삭제할 노드가 없는 경우
	return 0;
}

void printHashTable() {
	int i;

	for (i = 0; i < M; i++) {

		struct _hashTable* curr = H[i].next;; //순회

		while (curr != NULL) {
			printf(" %d", curr->key);
			curr = curr->next;
		}
	}

	printf("\n");

	return;
}