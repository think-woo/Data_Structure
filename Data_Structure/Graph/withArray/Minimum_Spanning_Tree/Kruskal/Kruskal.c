//Kruskal 알고리즘을 이용한 최소신장트리 출력(배열로 구현한 간선리스트 사용)
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

//데이터

//정점 구조체
struct VerticesArray {
	int vertexNum; //정점번호
};

//정점리스트
struct VerticesArray* VerticesArrayList;

//간선 구조체
struct EdgesArray {
	int vertexNum1;
	int vertexNum2;
	int weight;
};

//간선리스트
struct EdgesArray* EdgesArrayList;

//정점의 개수
int n;

//간선의 개수
int m;

//메소드

//정점 v와 정점 w 사이에 무게를 가진 간선을 생성, 변경
//무방향간선이므로, v와 w의 순서는 상관하지 않는다
//알고리즘 이론상 간선을 반환해야 하나, 문제상 생략
void insertEdge(int index, int vertexNum1, int vertexNum2, int weight);

//Kruskal 알고리즘을 이용한 최소신장트리 출력
void MST();

//간선의 무게에 따라 배열을 오름차순으로 정렬
//해당 배열을 큐처럼 사용
void sortQueue();


int main() {

	scanf("%d %d", &n, &m);

	//정점 및 정점리스트 생성
	VerticesArrayList = malloc(sizeof(struct VerticesArray) * n);
	for (int i = 0; i < n; i++) {
		VerticesArrayList[i].vertexNum = (i + 1);
	}

	//간선 및 간선리스트 생성
	EdgesArrayList = malloc(sizeof(struct EdgesArray) * m);
	int vertexNum1, vertexNum2, weight;
	for (int i = 0; i < m; i++) {

		scanf("%d %d %d", &vertexNum1, &vertexNum2, &weight);
		insertEdge(i, vertexNum1, vertexNum2, weight);
	}

	MST();

	return 0;

}//main()

void insertEdge(int index, int vertexNum1, int vertexNum2, int weight) {

	//간선 생성
	EdgesArrayList[index].vertexNum1 = vertexNum1;
	EdgesArrayList[index].vertexNum2 = vertexNum2;
	EdgesArrayList[index].weight = weight;

	return;

}//insertEdge()

void MST() {

	//1. 모든 정점에 대한 각각의 배낭 생성(분리집합)
	int* disjointSet = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		disjointSet[i] = i + 1;
	}

	
	//2. 간선을 큐에 삽입
	//문제상 구현의 단순화를 위해 간선리스트를 큐로 간주하고 오름차순으로 정렬
	sortQueue();
	
	//3. 간선의 수가 (정점-1)될 때까지 큐 삭제하면서 MST생성
	int totalWeigh = 0;
	int count = 0; //현재 담은 간선의 개수

	for (int i = 0; i < m; i++) {

		//해당 간선의 정점이 
		if (disjointSet[EdgesArrayList[i].vertexNum1 - 1] != disjointSet[EdgesArrayList[i].vertexNum2 - 1]) {
			printf(" %d", EdgesArrayList[i].weight);
			totalWeigh += EdgesArrayList[i].weight;

			int beforeSet = disjointSet[EdgesArrayList[i].vertexNum1 - 1]; //변경 전 소속
			int AfterSet = disjointSet[EdgesArrayList[i].vertexNum2 - 1]; //변경 후 소속
			for (int j = 0; j < n; j++) {
				if (disjointSet[j] == beforeSet) {
					disjointSet[j] = AfterSet;
				}
			}//for

			count++;
		}

		//간선의 수가 (정점-1)될 때까지
		if (count == n - 1) {
			break;
		}
	}//for
	
	printf("\n%d\n", totalWeigh);
	
}//MST()

void sortQueue() {

	//버블정렬
	for (int i = 0; i < (m - 1); i++) {
		for (int j = 0; j < (m - 1); j++) {
			if (EdgesArrayList[j].weight > EdgesArrayList[j + 1].weight) {
				struct EdgesArray temp;
				temp = EdgesArrayList[j];
				EdgesArrayList[j] = EdgesArrayList[j + 1];
				EdgesArrayList[j + 1] = temp;
			}//if
		}//for
	}//for

}//sortQueue()