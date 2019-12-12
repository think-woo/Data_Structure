//인접리스트를 배열로 구현
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

//데이터

//정점 구조체
struct VerticesArray {
	int nodeNum;
	struct IncidenceNode* incidenceListHead;
};

//간선 구조체
struct EdgesArray {
	int nodeIndex1;
	int nodeIndex2;
	int weight;
};

//부착리스트 구조체
struct IncidenceNode {
	int edgeIndex;
	struct IncidenceNode* nextIncidence;
};

//정점리스트
struct VerticesArray* VerticesArrayList;

//간선리스트
struct EdgesArray* EdgesArrayList;

//메소드

//정점의 부착리스트 생성
struct IncidenceNode* insertIncidence();

//해당 숫자를 지닌 (고립된) 정점 생성
//알고리즘 이론상 해당 정점을 반환해야 하나, 문제상 생략
void insertVertex(int nodeNum);

//정점 v와 정점 w 사이에 가중치를 가진 간선을 생성, 변경
//알고리즘 이론상 간선을 반환해야 하나, 문제상 생략
void insertEdge(int nodeNum1, int nodeNum2, int weight);

//정점에서 인접한 정점과 해당 간선의 가중치를 출력
//알고리즘 이론상 모든 정점을 반환해야 하나, 문제상 생략
void adjacentVertices(int nodeNum);



int main() {

	//정점리스트 초기화
	VerticesArrayList = malloc(sizeof(struct VerticesArray) * 6);
	for (int i = 0; i < 6; i++) {
		VerticesArrayList[i].nodeNum = -1;
		VerticesArrayList[i].incidenceListHead = insertIncidence();
	}

	//간선리스트 초기화
	EdgesArrayList = malloc(sizeof(struct EdgesArray) * 21);
	int count = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = i; j < 6; j++) {
			EdgesArrayList[count].nodeIndex1 = i;
			EdgesArrayList[count].nodeIndex2 = j;
			EdgesArrayList[count].weight = 0;
			count++;
		}
	}
	//그래프 설정
	insertVertex(1);
	insertVertex(2);
	insertVertex(3);
	insertVertex(4);
	insertVertex(5);
	insertVertex(6);

	insertEdge(1, 2, 1);
	insertEdge(1, 3, 1);
	insertEdge(1, 4, 1);
	insertEdge(1, 6, 2);

	insertEdge(2, 3, 1);

	insertEdge(3, 5, 4);

	insertEdge(5, 5, 4);
	insertEdge(5, 6, 3);

	//명령어
	char command;
	int vertexNum1, vertexNum2, weight;

	scanf("%c", &command);

	while (command != 'q') {
		if (command == 'a') {
			scanf("%d", &vertexNum1);
			adjacentVertices(vertexNum1);

		}

		if (command == 'm') {
			scanf("%d %d %d", &vertexNum1, &vertexNum2, &weight);
			insertEdge(vertexNum1, vertexNum2, weight);
		}

		scanf("%c", &command);
	}

	return 0;

}//main()

struct IncidenceNode* insertIncidence() {

	struct IncidenceNode* newIncidence = malloc(sizeof(struct IncidenceNode));

	newIncidence->edgeIndex = NULL;
	newIncidence->nextIncidence = NULL;

	return newIncidence;

}//insertIncidence()

void insertVertex(int nodeNum) {

	VerticesArrayList[nodeNum - 1].nodeNum = nodeNum;

}//insertVertex()

void insertEdge(int nodeNum1, int nodeNum2, int weight) {

	// 정점 탐색
	struct VerticesArray* vertex1 = &VerticesArrayList[nodeNum1 - 1];
	struct VerticesArray* vertex2 = &VerticesArrayList[nodeNum2 - 1];

	// 1. 정점이 하나라도 없는 경우
	if (nodeNum1 > 6 || nodeNum1 < 0) { //배열인덱스 범위 안일 경우
		printf("-1\n");
		return;
	}
	else {
		if (vertex1->nodeNum == -1) { //배열인덱스 범위 밖일 경우
			printf("-1\n");
			return;
		}
	}

	if (nodeNum2 > 6 || nodeNum2 < 0) { //배열인덱스 범위 안일 경우
		printf("-1\n");
		return;
	}
	else {
		if (vertex2->nodeNum == -1) { //배열인덱스 범위 밖일 경우
			printf("-1\n");
			return;
		}
	}

	if (vertex1->nodeNum == NULL || vertex2->nodeNum == NULL) {
		printf("-1\n");
		return;
	}

	// 간선 탐색
	int min = (nodeNum1 <= nodeNum2) ? nodeNum1 : nodeNum2;

	int sum = 0;
	for (int i = 0; i < min - 1; i++) {
		sum = sum + (5 - i);
	}

	//정점 인덱스 + 정점 인덱스 + 누적되는 인덱스 값 - 작은 정점의 인덱스
	int edgeIndex = (nodeNum1 - 1) + (nodeNum2 - 1) + sum - (min - 1);

	struct EdgesArray* currEdge = &EdgesArrayList[edgeIndex];

	// 3. weight가 0이면, 정점 삭제
	if (weight == 0) {
		// 3-1. 각 정점의 부착리스트 갱신
		struct IncidenceNode* previousIncidence = vertex1->incidenceListHead; //NULL
		struct IncidenceNode* currIncidence = previousIncidence->nextIncidence;

		while (currIncidence != NULL) {
			if (&EdgesArrayList[currIncidence->edgeIndex] == currEdge) {
				previousIncidence->nextIncidence = currIncidence->nextIncidence;
			}

			previousIncidence = previousIncidence->nextIncidence;
			currIncidence = currIncidence->nextIncidence;
		}

		previousIncidence = vertex2->incidenceListHead; //NULL
		currIncidence = previousIncidence->nextIncidence;

		while (currIncidence != NULL) {
			if (&EdgesArrayList[currIncidence->edgeIndex] == currEdge) {
				previousIncidence->nextIncidence = currIncidence->nextIncidence;
			}

			previousIncidence = previousIncidence->nextIncidence;
			currIncidence = currIncidence->nextIncidence;
		}

		// 3-2. 간선리시트 갱신
		currEdge->weight = 0;

		return;

	}//if

	// 4. 간성 생성
	// 4-1. 각 정점의 부착리스트 갱신
	struct IncidenceNode* newIncidence1 = insertIncidence();
	newIncidence1->nextIncidence = vertex1->incidenceListHead->nextIncidence;
	vertex1->incidenceListHead->nextIncidence = newIncidence1;

	struct IncidenceNode* newIncidence2 = insertIncidence();
	newIncidence2->nextIncidence = vertex2->incidenceListHead->nextIncidence;
	vertex2->incidenceListHead->nextIncidence = newIncidence2;

	// 4-2. 간선리스트 갱신
	currEdge->weight = weight;

	return;

}//insertEdge()

void adjacentVertices(int nodeNum) {

	// 정점 탐색
	struct VerticesArray* vertex = &VerticesArrayList[nodeNum - 1];

	// 1. 정점이 없는 경우
	if (nodeNum > 6 || nodeNum < 0) { //배열인덱스 범위 안일 경우
		printf("-1\n");
		return;
	}
	else {
		if (vertex->nodeNum == -1) { //배열인덱스 범위 밖일 경우
			printf("-1\n");
			return;
		}
	}

	// 2.(정점번호, 간선가중치)를 정점번호의 오름차순으로 출력
	for (int i = 0; i < 21; i++) {
		if (EdgesArrayList[i].weight != 0) {
			if (EdgesArrayList[i].nodeIndex1 == nodeNum - 1) {
				printf("%d %d ", EdgesArrayList[i].nodeIndex2 + 1, EdgesArrayList[i].weight);
			}
			else if (EdgesArrayList[i].nodeIndex2 == nodeNum - 1) {
				printf("%d %d ", EdgesArrayList[i].nodeIndex1 + 1, EdgesArrayList[i].weight);
			}
		}
	}//for

	printf("\n");

}//adjacentVertices()
