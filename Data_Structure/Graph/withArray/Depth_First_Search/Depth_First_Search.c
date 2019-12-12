//�迭�� ������ ��������Ʈ�� ���̿켱Ž���� ����
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

//������

//���� ����ü
struct VerticesArray {
	int vertexNum;
	int isVisited;
	struct IncidenceNode* incidenceListHead;
};

//��������Ʈ ����ü
struct IncidenceNode {
	int adjacentVertexNum;
	int isPassed;

	struct IncidenceNode* nextIncidence;
};

//��������Ʈ
struct VerticesArray* VerticesArrayList;

//������ ����
int n;

//������ ����
int m;

//��ȸ���� ���� ��ȣ
int s;

//�޼ҵ�

//������ ��������Ʈ ����
struct IncidenceNode* createIncidence();

//���� v�� ���� w ���̿� ������ ����, ����
//�����Ⱓ���̹Ƿ�, v�� w�� ������ ������� �ʴ´�
//�˰��� �̷л� ������ ��ȯ�ؾ� �ϳ�, ������ ����
void insertEdge(int vertexNum1, int vertexNum2);

//�ش� ������ �����ϴ� ������ ��ȣ�� ��������Ʈ�� �߰�
void insertIncidence(struct VerticesArray* vertex, int adjacentVertexNum);

//���̿켱Ž��
void DFS(int startVertex);

//���̿켱Ž���� ������ ���� ����Լ�
void rDFS(struct VerticesArray* startVertex);



int main() {

	scanf("%d %d %d", &n, &m, &s);

	//��������Ʈ �ʱ�ȭ
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

	// 1. ���� Ž��
	struct VerticesArray* vertex1 = &VerticesArrayList[vertexNum1 - 1];
	struct VerticesArray* vertex2 = &VerticesArrayList[vertexNum2 - 1];

	// 2. ���� ����
	// �� ������ ��������Ʈ ����
	insertIncidence(vertex1, vertexNum2);
	insertIncidence(vertex2, vertexNum1);

	return;

}//insertEdge()

void insertIncidence(struct VerticesArray* vertex, int adjacentVertexNum){

	// 1. ��������Ʈ�� �� ���
	if (vertex->incidenceListHead->nextIncidence == NULL) {
		vertex->incidenceListHead->nextIncidence = createIncidence();
		vertex->incidenceListHead->nextIncidence->adjacentVertexNum = adjacentVertexNum;

		return;
	}

	// 2. ��������Ʈ�� �ִ� ���
	struct IncidenceNode* previous = vertex->incidenceListHead;
	struct IncidenceNode* curr = vertex->incidenceListHead->nextIncidence;

	struct IncidenceNode* newIncidence = createIncidence();

	// 2-1. ��������Ʈ �߰��� ����
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

	// 2-2.��������Ʈ ���� ����
	previous->nextIncidence = newIncidence;

	newIncidence->adjacentVertexNum = adjacentVertexNum;

	return;
}


void DFS(int startVertex){

	
	/*
	�󺧸� ����

	����
	Fresh >> 0
	Visited >> 1
	
	����(��������Ʈ �ȿ� ����)
	Fresh >> 0
	Tree >> 1
	Back >> -1
	*/
	
	//1. ���� �󺧸�
	for (int i = 0; i < n; i++) {
		VerticesArrayList[i].isVisited = 0;
	}

	// 2. ���� �󺧸�
	for (int i = 0; i <n; i++) {

		struct IncidenceNode* curr = VerticesArrayList[i].incidenceListHead->nextIncidence;

		while (curr != NULL) {
			curr->isPassed = 0;
			curr = curr->nextIncidence;
		}

	}//for

	// 3. ���̿켱Ž�� ����
	rDFS(&VerticesArrayList[startVertex-1]);

	return;

}//DFS()

void rDFS(struct VerticesArray* startVertex) {

	// 1. ���� �湮
	startVertex->isVisited = 1;
	printf("%d\n", startVertex->vertexNum);

	// 2. �������� �湮
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
