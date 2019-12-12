//배열로 구현한 인접행렬로 너비우선탐색을 구현
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

//데이터

//정점 구조체
struct VerticesArray {
	int vertexNum;
	int isVisited;
};

//인접행렬에 담을 정보 구조체
struct AdjacentVertex {
	int isConnected;
	int isPassed;
};

//정점리스트
struct VerticesArray* VerticesArrayList;

//인접행렬
struct AdjacentVertex** AdjacentVertexMatrix;

//너비우선탐색에서 사용할 리스트 구조체
struct LevelInfo {
	int num;
	struct LevelInfo* next;
};

//정점의 개수
int n;

//간선의 개수
int m;

//순회시작 정점 번호
int s;

//메소드

//정점 v와 정점 w 사이에 간선을 생성, 변경
//무방향간선이므로, v와 w의 순서는 상관하지 않는다
//알고리즘 이론상 간선을 반환해야 하나, 문제상 생략
void insertEdge(int vertexNum1, int vertexNum2);

//너비우선탐색
void BFS(int startVertex);

//깊이우선탐색을 실행할 내부 재귀함수
void BFS1(int startVertex);

//레벨리스트에 레벨정보를 추가
struct LevelInfo* insertLevelInfo(int VertexIndex);

int main() {

	scanf("%d %d %d", &n, &m, &s);

	//정점리스트 초기화
	VerticesArrayList = malloc(sizeof(struct VerticesArray) * n);
	for (int i = 0; i < n; i++) {
		VerticesArrayList[i].vertexNum = (i + 1);
	}

	//인접행렬 초기화
	AdjacentVertexMatrix = (struct VerticesArray**)malloc(sizeof(struct VerticesArray*) * n);
	for (int i = 0; i < n; i++) {
		AdjacentVertexMatrix[i] = (struct VerticesArray*)malloc(sizeof(struct VerticesArray) * n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AdjacentVertexMatrix[i][j].isConnected = -1;
		}
	}

	int vertexNum1, vertexNum2;
	for (int i = 0; i < m; i++) {

		scanf("%d %d", &vertexNum1, &vertexNum2);
		insertEdge(vertexNum1, vertexNum2);
	}

	BFS(s);


	return 0;

}//main()

void insertEdge(int vertexNum1, int vertexNum2) {

	// 간선 생성
	// 인접행렬 갱신
	AdjacentVertexMatrix[vertexNum1 - 1][vertexNum2 - 1].isConnected = 1;
	AdjacentVertexMatrix[vertexNum2 - 1][vertexNum1 - 1].isConnected = 1;

	return;

}//insertEdge()


void BFS(int startVertex){

	
	/*
	라벨링 상태

	정점 isVisited
	Fresh >> 0
	Visited >> 1
	
	간선(인정행렬 안에 구현) isPassed
	Fresh >> 0
	Tree >> 1
	Crossed >> -1
	*/
	
	//1. 정점 라벨링
	for (int i = 0; i < n; i++) {
		VerticesArrayList[i].isVisited = 0;
	}

	// 2. 간선 라벨링
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (AdjacentVertexMatrix[i][j].isConnected == 1) {
				AdjacentVertexMatrix[i][j].isPassed = 0;
			}
		}
	}//for

	// 3. 너비우선탐색 시작
	BFS1(startVertex);

	return;

}// BFS()

void BFS1(int startVertex) {

	// 1. 정점 방문
	VerticesArrayList[startVertex - 1].isVisited = 1;
	printf("%d\n", VerticesArrayList[startVertex - 1].vertexNum);

	// 레벨리스트 초기화
	// 처음 노드는 헤드노드 사용
	struct LevelInfo LevelList[100];
	for (int i = 0; i < 100; i++) {
		LevelList[i].num = -1;
		LevelList[i].next = NULL;
	}

	LevelList[0].next = insertLevelInfo(startVertex - 1); //정점의 인덱스
 

	// 2. 인점정점 방문
	int levelListIndex = 0;
	struct LevelInfo* currLevel = LevelList[levelListIndex].next; //LevelList[0]의 첫 번째 원소
	struct LevelInfo* nextLevel = &LevelList[levelListIndex + 1];

	do {

		while (currLevel != NULL) {

			for (int i = 0; i < n; i++) {
				if (AdjacentVertexMatrix[currLevel->num][i].isConnected == 1) {
					if (AdjacentVertexMatrix[currLevel->num][i].isPassed == 0) {

						if (VerticesArrayList[i].isVisited == 0) {
							AdjacentVertexMatrix[currLevel->num][i].isPassed = 1;
							VerticesArrayList[i].isVisited = 1;
							printf("%d\n", VerticesArrayList[i].vertexNum);

							struct LevelInfo* newNode = insertLevelInfo(i);
							nextLevel->next = newNode;
							nextLevel = newNode;

						}//if
						else {//VerticesArrayList[i].isVisited == 1
							AdjacentVertexMatrix[currLevel->num][i].isPassed = -1;
						}//else

					}//if
				}//if
			}//for

			currLevel = currLevel->next;

		}//while

		levelListIndex++;
		currLevel = LevelList[levelListIndex].next;
		nextLevel = &LevelList[levelListIndex + 1];

	} while (currLevel != NULL);

	return;

}// BFS1()

struct LevelInfo* insertLevelInfo(int VertexIndex) {

	struct LevelInfo* new = malloc(sizeof(struct LevelInfo));

	new->num = VertexIndex;
	new->next = NULL;

	return new;

}//insertLevelInfo();
