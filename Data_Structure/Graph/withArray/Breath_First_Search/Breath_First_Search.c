//�迭�� ������ ������ķ� �ʺ�켱Ž���� ����
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

//������

//���� ����ü
struct VerticesArray {
	int vertexNum;
	int isVisited;
};

//������Ŀ� ���� ���� ����ü
struct AdjacentVertex {
	int isConnected;
	int isPassed;
};

//��������Ʈ
struct VerticesArray* VerticesArrayList;

//�������
struct AdjacentVertex** AdjacentVertexMatrix;

//�ʺ�켱Ž������ ����� ����Ʈ ����ü
struct LevelInfo {
	int num;
	struct LevelInfo* next;
};

//������ ����
int n;

//������ ����
int m;

//��ȸ���� ���� ��ȣ
int s;

//�޼ҵ�

//���� v�� ���� w ���̿� ������ ����, ����
//�����Ⱓ���̹Ƿ�, v�� w�� ������ ������� �ʴ´�
//�˰��� �̷л� ������ ��ȯ�ؾ� �ϳ�, ������ ����
void insertEdge(int vertexNum1, int vertexNum2);

//�ʺ�켱Ž��
void BFS(int startVertex);

//���̿켱Ž���� ������ ���� ����Լ�
void BFS1(int startVertex);

//��������Ʈ�� ���������� �߰�
struct LevelInfo* insertLevelInfo(int VertexIndex);

int main() {

	scanf("%d %d %d", &n, &m, &s);

	//��������Ʈ �ʱ�ȭ
	VerticesArrayList = malloc(sizeof(struct VerticesArray) * n);
	for (int i = 0; i < n; i++) {
		VerticesArrayList[i].vertexNum = (i + 1);
	}

	//������� �ʱ�ȭ
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

	// ���� ����
	// ������� ����
	AdjacentVertexMatrix[vertexNum1 - 1][vertexNum2 - 1].isConnected = 1;
	AdjacentVertexMatrix[vertexNum2 - 1][vertexNum1 - 1].isConnected = 1;

	return;

}//insertEdge()


void BFS(int startVertex){

	
	/*
	�󺧸� ����

	���� isVisited
	Fresh >> 0
	Visited >> 1
	
	����(������� �ȿ� ����) isPassed
	Fresh >> 0
	Tree >> 1
	Crossed >> -1
	*/
	
	//1. ���� �󺧸�
	for (int i = 0; i < n; i++) {
		VerticesArrayList[i].isVisited = 0;
	}

	// 2. ���� �󺧸�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (AdjacentVertexMatrix[i][j].isConnected == 1) {
				AdjacentVertexMatrix[i][j].isPassed = 0;
			}
		}
	}//for

	// 3. �ʺ�켱Ž�� ����
	BFS1(startVertex);

	return;

}// BFS()

void BFS1(int startVertex) {

	// 1. ���� �湮
	VerticesArrayList[startVertex - 1].isVisited = 1;
	printf("%d\n", VerticesArrayList[startVertex - 1].vertexNum);

	// ��������Ʈ �ʱ�ȭ
	// ó�� ���� ����� ���
	struct LevelInfo LevelList[100];
	for (int i = 0; i < 100; i++) {
		LevelList[i].num = -1;
		LevelList[i].next = NULL;
	}

	LevelList[0].next = insertLevelInfo(startVertex - 1); //������ �ε���
 

	// 2. �������� �湮
	int levelListIndex = 0;
	struct LevelInfo* currLevel = LevelList[levelListIndex].next; //LevelList[0]�� ù ��° ����
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
