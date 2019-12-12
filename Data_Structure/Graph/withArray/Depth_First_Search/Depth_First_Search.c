//배열로 구현한 인접리스트로 깊이우선탐색을 구현
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

//데이터

//정점 구조체
struct VerticesArray {
	int vertexNum;
	int isVisited;
	struct IncidenceNode* incidenceListHead;
};

//부착리스트 구조체
struct IncidenceNode {
	int adjacentVertexNum;
	int isPassed;

	struct IncidenceNode* nextIncidence;
};

//정점리스트
struct VerticesArray* VerticesArrayList;

//정점의 개수
int n;

//간선의 개수
int m;

//순회시작 정점 번호
int s;

//메소드

//정점의 부착리스트 생성
struct IncidenceNode* createIncidence();

//정점 v와 정점 w 사이에 간선을 생성, 변경
//무방향간선이므로, v와 w의 순서는 상관하지 않는다
//알고리즘 이론상 간선을 반환해야 하나, 문제상 생략
void insertEdge(int vertexNum1, int vertexNum2);

//해당 정점에 인접하는 정점의 번호를 부착리스트에 추가
void insertIncidence(struct VerticesArray* vertex, int adjacentVertexNum);

//깊이우선탐색
void DFS(int startVertex);

//깊이우선탐색을 실행할 내부 재귀함수
void rDFS(struct VerticesArray* startVertex);



int main() {

	scanf("%d %d %d", &n, &m, &s);

	//정점리스트 초기화
	VerticesArrayList = malloc(sizeof(struct VerticesArray) * n);
	for (int i = 0; i < n; i++) {
		VerticesArrayList[i].vertexNum = (i + 1);
		VerticesArrayList[i].incidenceListHead = createIncidence();
	}

	int vertexNum1, vertexNum2;
	for (int i = 0; i < m; i++) {

		scanf("%d %d", &vertexNum1, &vertexNum2);
		insertEdge(vertexNum1, vertexNum2);
	}

	DFS(s);

	return 0;

}//main()

struct IncidenceNode* createIncidence() {

	struct IncidenceNode* newIncidence = malloc(sizeof(struct IncidenceNode));

	newIncidence->adjacentVertexNum = -1;
	newIncidence->isPassed = -2;
	newIncidence->nextIncidence = NULL;

	return newIncidence;

}//createIncidence()

void insertEdge(int vertexNum1, int vertexNum2) {

	// 1. 정점 탐색
	struct VerticesArray* vertex1 = &VerticesArrayList[vertexNum1 - 1];
	struct VerticesArray* vertex2 = &VerticesArrayList[vertexNum2 - 1];

	// 2. 간선 생성
	// 각 정점의 부착리스트 갱신
	insertIncidence(vertex1, vertexNum2);
	insertIncidence(vertex2, vertexNum1);

	return;

}//insertEdge()

void insertIncidence(struct VerticesArray* vertex, int adjacentVertexNum){

	// 1. 부착리스트가 빈 경우
	if (vertex->incidenceListHead->nextIncidence == NULL) {
		vertex->incidenceListHead->nextIncidence = createIncidence();
		vertex->incidenceListHead->nextIncidence->adjacentVertexNum = adjacentVertexNum;

		return;
	}

	// 2. 부착리스트가 있는 경우
	struct IncidenceNode* previous = vertex->incidenceListHead;
	struct IncidenceNode* curr = vertex->incidenceListHead->nextIncidence;

	struct IncidenceNode* newIncidence = createIncidence();

	// 2-1. 부착리스트 중간에 갱신
	while (curr != NULL) {
		if (curr->adjacentVertexNum > adjacentVertexNum) {
			previous->nextIncidence = newIncidence;
			newIncidence->nextIncidence = curr;

			newIncidence->adjacentVertexNum = adjacentVertexNum;

			return;
		}

		previous = previous->nextIncidence;
		curr = curr->nextIncidence;

	}//while

	// 2-2.부착리스트 끝에 갱신
	previous->nextIncidence = newIncidence;

	newIncidence->adjacentVertexNum = adjacentVertexNum;

	return;
}


void DFS(int startVertex){

	
	/*
	라벨링 상태

	정점
	Fresh >> 0
	Visited >> 1
	
	간선(부착리스트 안에 구현)
	Fresh >> 0
	Tree >> 1
	Back >> -1
	*/
	
	//1. 정점 라벨링
	for (int i = 0; i < n; i++) {
		VerticesArrayList[i].isVisited = 0;
	}

	// 2. 간선 라벨링
	for (int i = 0; i <n; i++) {

		struct IncidenceNode* curr = VerticesArrayList[i].incidenceListHead->nextIncidence;

		while (curr != NULL) {
			curr->isPassed = 0;
			curr = curr->nextIncidence;
		}

	}//for

	// 3. 깊이우선탐색 시작
	rDFS(&VerticesArrayList[startVertex-1]);

	return;

}//DFS()

void rDFS(struct VerticesArray* startVertex) {

	// 1. 정점 방문
	startVertex->isVisited = 1;
	printf("%d\n", startVertex->vertexNum);

	// 2. 인점정점 방문
	struct IncidenceNode* currIncidence = startVertex->incidenceListHead->nextIncidence;
	
	while (currIncidence != NULL) {
		if (currIncidence->isPassed == 0) {
			if (VerticesArrayList[currIncidence->adjacentVertexNum - 1].isVisited == 0) {
				currIncidence->isPassed = 1;
				rDFS(&VerticesArrayList[currIncidence->adjacentVertexNum - 1]);
			}
			else {
				currIncidence->isPassed = -1;
			}
		}

		currIncidence = currIncidence->nextIncidence;

	}//while

	return;

}//rDFS()
