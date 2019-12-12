//Prim-Jarnik 알고리즘을 이용한 최소신장트리 출력(배열로 구현한 인접리스트 사용)
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

//데이터

//정점 구조체
struct VerticesArray {
	int vertexNum; //정점번호
	int weight; //현재 배낭 안과 배낭 밖의 간선 무게
	struct VerticesArray* parent; //배낭 안을 들어가서 해당 정점의 부모정점
	struct IncidenceNode* IncidenceListHead; //해당 정점의 부착리스트의 헤드(빈값)
};

//정점리스트
struct VerticesArray* VerticesArrayList;

//부착리스트
struct IncidenceNode {
	int adjacentVertexNum; //인접하는 정점의 번호
	int adjacentVertexWeight; //인접하는 정점을 잇는 간선의 무게
	struct IncidenceNode* next; //다음 부탁리스트
};

//정점의 개수
int n;

//간선의 개수
int m;

//메소드

//부착리스트 생성
struct IncidenceNode* createIncidenceNode();

//정점 v와 정점 w 사이에 무게를 가진 간선을 생성, 변경
//무방향간선이므로, v와 w의 순서는 상관하지 않는다
//알고리즘 이론상 간선을 반환해야 하나, 문제상 생략
void insertEdge(int vertexNum1, int vertexNum2, int weight);

//Prim-Jarnik 알고리즘을 이용한 최소신장트리 출력
void MST(int startVertex);

//정점의 무게에 따라 배열을 오름차순으로 정렬
//해당 배열을 큐처럼 사용
void sortQueue(int startIndex);


int main() {

	scanf("%d %d", &n, &m);

	//정점 및 정점리스트 생성
	VerticesArrayList = malloc(sizeof(struct VerticesArray) * n);
	for (int i = 0; i < n; i++) {
		VerticesArrayList[i].vertexNum = (i + 1);
		VerticesArrayList[i].IncidenceListHead = createIncidenceNode();
	}

	//간선 생성
	int vertexNum1, vertexNum2, weight;
	for (int i = 0; i < m; i++) {

		scanf("%d %d %d", &vertexNum1, &vertexNum2, &weight);
		insertEdge(vertexNum1, vertexNum2, weight);
	}

	MST(1);

	return 0;

}//main()

struct IncidenceNode* createIncidenceNode() {

	struct IncidenceNode* newIncidence = malloc(sizeof(struct IncidenceNode));

	newIncidence->adjacentVertexNum = -1;
	newIncidence->adjacentVertexWeight = -1;
	newIncidence->next = NULL;

	return newIncidence;

}//createIncidenceNode()

void insertEdge(int vertexNum1, int vertexNum2, int weight) {

	//간선 생성
	//문제상 굳히 간선 구조체와 간선리스트를 설정하지 않고, 바로 해당 정점의 부착리스트를 갱신한다

	//첫 번째 정점 갱신
	struct VerticesArray* vertex1 = &VerticesArrayList[vertexNum1 - 1];
	struct IncidenceNode* newIncidence1 = createIncidenceNode();

	newIncidence1->next = vertex1->IncidenceListHead->next;
	vertex1->IncidenceListHead->next = newIncidence1;

	newIncidence1->adjacentVertexNum = vertexNum2;
	newIncidence1->adjacentVertexWeight = weight;

	//두 번째 정점 갱신
	struct VerticesArray* vertex2 = &VerticesArrayList[vertexNum2 - 1];
	struct IncidenceNode* newIncidence2 = createIncidenceNode();

	newIncidence2->next = vertex2->IncidenceListHead->next;
	vertex2->IncidenceListHead->next = newIncidence2;

	newIncidence2->adjacentVertexNum = vertexNum1;
	newIncidence2->adjacentVertexWeight = weight;

	return;

}//insertEdge()

void MST(int startVertex) {

	//1. 모든 정점의 무게와 배낭 초기화
	for (int i = 0; i < n; i++) {
		VerticesArrayList[i].weight = 9999;
		VerticesArrayList[i].parent = NULL;
	}

	//2. 시작 정점 설정
	struct VerticesArray* vertex = &VerticesArrayList[startVertex - 1];
	vertex->weight = 0;



	//3. 정점의 무게를 키값으로 하는 큐 생성
	//문제상 굳히 큐를 생성하지 않고 배열로 구현한 정점리스트를 큐로 취급한다
	sortQueue(0);

	//4. 큐의 원소를 하나씩 제거하면서 MST(최소신장트리) 출력

	int totalWeight = 0;
	for (int i = 0; i < n; i++) {

		//탐색한 정점 출력
		printf(" %d", VerticesArrayList[i].vertexNum);
		totalWeight += VerticesArrayList[i].weight;

		//해당 정점과 인접한 정점 검사
		struct IncidenceNode* curr = VerticesArrayList[i].IncidenceListHead->next;
		while (curr != NULL) {

			for (int j = i + 1; j < n; j++) {
				if (curr->adjacentVertexNum == VerticesArrayList[j].vertexNum) { //해당 정점이 큐 안에 존재하는 경우
					if (VerticesArrayList[j].weight > curr->adjacentVertexWeight) {//해당 정점의 현재 무게가 배낭 안과 밖을 이어주는 무게보다 큰 경우

						VerticesArrayList[j].weight = curr->adjacentVertexWeight;
						VerticesArrayList[j].parent = &VerticesArrayList[i];

						sortQueue(i + 1); //현재 반복문에서 제거한 큐 바로 뒤부터 정렬

						break; //찾으면 다음 간선 정보로 넘어가면 된다
					}//if
				}//if
			}//for
			curr = curr->next;
		}//while

	}//for

	printf("\n%d", totalWeight);

}//MST()

void sortQueue(int startIndex) {

	//버블정렬
	for (int i = startIndex; i < (n - 1); i++) {
		for (int j = startIndex; j < (n - 1); j++) {
			if (VerticesArrayList[j].weight > VerticesArrayList[j + 1].weight) {
				struct VerticesArray temp;
				temp = VerticesArrayList[j];
				VerticesArrayList[j] = VerticesArrayList[j + 1];
				VerticesArrayList[j + 1] = temp;
			}//if
		}//for
	}//for

}//sortQueue()

