//해시테이블의 개방 주소법 구현
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _hashTable {
	int key;
	int isEmpty; //0 == 비어있음, 1 == 활성, -1 == 비활성
};

//전역변수
struct _hashTable* H;
int M; //hastTableSize;
int N; //변수 갯수
int q; //이중해싱에서 사용할 소수

//함수
int hash(int key); //해시함수
int hash2(int key); //이중해싱에서 사용할 해시함수
void initBucketArray(); //해시테이블 초기화
int getNextBucket(int v, int i, int key); //다음 bucket주소를 반환
void insertElement(int key); //키 삽입 및 삽입한 bucket주소를 출력
int findElement(int key); //키 탐색 및 원소 반환 //문제풀이상 없으면 -1, 있으면 bucket주소를 출력
void printHashTable(); //해시테이블 출력

int main() {

	//hastTableSize, 변수 갯수, 이중해싱 소수 입력
	scanf("%d %d %d", &M, &N, &q);

	int key; //키값
	char command; //명령어

	//초기화
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
//선형조사법
int getNextBucket(int v, int i)
{
	return (v+i)%M;
}

//2차조사법
int getNextBucket(int v, int i)
{
	return (v + i*i) % M;
}
*/
//이중해싱
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

		if (H[b].isEmpty == 1) { //bucket에 키값이 있는 상태
			printf("C");
		}
		else { //bucket에 키값이 있는지 비활성되어있거나, 없는상태
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

		if (H[b].isEmpty == 1) { //bucket에 키값이 있는 상태(활성)
			if (H[b].key == key) { //탐색한 키값이 있는 경우
				printf("%d %d\n", b, key);
				return;
			}
		}
	}

	//3. 키값이 없는 경우
	printf("-1\n");
}

void printHashTable() {

	for (int i = 0; i < M; i++) {
		printf(" %d", H[i].key);
	}

	printf("\n");

	return;
}