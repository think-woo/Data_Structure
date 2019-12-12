//��������Ʈ�� �迭�� ����
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

//������

//���� ����ü
struct VerticesArray {
	int nodeNum;
	struct IncidenceNode* incidenceListHead;
};

//���� ����ü
struct EdgesArray {
	int nodeIndex1;
	int nodeIndex2;
	int weight;
};

//��������Ʈ ����ü
struct IncidenceNode {
	int edgeIndex;
	struct IncidenceNode* nextIncidence;
};

//��������Ʈ
struct VerticesArray* VerticesArrayList;

//��������Ʈ
struct EdgesArray* EdgesArrayList;

//�޼ҵ�

//������ ��������Ʈ ����
struct IncidenceNode* insertIncidence();

//�ش� ���ڸ� ���� (����) ���� ����
//�˰��� �̷л� �ش� ������ ��ȯ�ؾ� �ϳ�, ������ ����
void insertVertex(int nodeNum);

//���� v�� ���� w ���̿� ����ġ�� ���� ������ ����, ����
//�˰��� �̷л� ������ ��ȯ�ؾ� �ϳ�, ������ ����
void insertEdge(int nodeNum1, int nodeNum2, int weight);

//�������� ������ ������ �ش� ������ ����ġ�� ���
//�˰��� �̷л� ��� ������ ��ȯ�ؾ� �ϳ�, ������ ����
void adjacentVertices(int nodeNum);



int main() {

	//��������Ʈ �ʱ�ȭ
	VerticesArrayList = malloc(sizeof(struct VerticesArray) * 6);
	for (int i = 0; i < 6; i++) {
		VerticesArrayList[i].nodeNum = -1;
		VerticesArrayList[i].incidenceListHead = insertIncidence();
	}

	//��������Ʈ �ʱ�ȭ
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
	//�׷��� ����
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

	//��ɾ�
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

	// ���� Ž��
	struct VerticesArray* vertex1 = &VerticesArrayList[nodeNum1 - 1];
	struct VerticesArray* vertex2 = &VerticesArrayList[nodeNum2 - 1];

	// 1. ������ �ϳ��� ���� ���
	if (nodeNum1 > 6 || nodeNum1 < 0) { //�迭�ε��� ���� ���� ���
		printf("-1\n");
		return;
	}
	else {
		if (vertex1->nodeNum == -1) { //�迭�ε��� ���� ���� ���
			printf("-1\n");
			return;
		}
	}

	if (nodeNum2 > 6 || nodeNum2 < 0) { //�迭�ε��� ���� ���� ���
		printf("-1\n");
		return;
	}
	else {
		if (vertex2->nodeNum == -1) { //�迭�ε��� ���� ���� ���
			printf("-1\n");
			return;
		}
	}

	if (vertex1->nodeNum == NULL || vertex2->nodeNum == NULL) {
		printf("-1\n");
		return;
	}

	// ���� Ž��
	int min = (nodeNum1 <= nodeNum2) ? nodeNum1 : nodeNum2;

	int sum = 0;
	for (int i = 0; i < min - 1; i++) {
		sum = sum + (5 - i);
	}

	//���� �ε��� + ���� �ε��� + �����Ǵ� �ε��� �� - ���� ������ �ε���
	int edgeIndex = (nodeNum1 - 1) + (nodeNum2 - 1) + sum - (min - 1);

	struct EdgesArray* currEdge = &EdgesArrayList[edgeIndex];

	// 3. weight�� 0�̸�, ���� ����
	if (weight == 0) {
		// 3-1. �� ������ ��������Ʈ ����
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

		// 3-2. ��������Ʈ ����
		currEdge->weight = 0;

		return;

	}//if

	// 4. ���� ����
	// 4-1. �� ������ ��������Ʈ ����
	struct IncidenceNode* newIncidence1 = insertIncidence();
	newIncidence1->nextIncidence = vertex1->incidenceListHead->nextIncidence;
	vertex1->incidenceListHead->nextIncidence = newIncidence1;

	struct IncidenceNode* newIncidence2 = insertIncidence();
	newIncidence2->nextIncidence = vertex2->incidenceListHead->nextIncidence;
	vertex2->incidenceListHead->nextIncidence = newIncidence2;

	// 4-2. ��������Ʈ ����
	currEdge->weight = weight;

	return;

}//insertEdge()

void adjacentVertices(int nodeNum) {

	// ���� Ž��
	struct VerticesArray* vertex = &VerticesArrayList[nodeNum - 1];

	// 1. ������ ���� ���
	if (nodeNum > 6 || nodeNum < 0) { //�迭�ε��� ���� ���� ���
		printf("-1\n");
		return;
	}
	else {
		if (vertex->nodeNum == -1) { //�迭�ε��� ���� ���� ���
			printf("-1\n");
			return;
		}
	}

	// 2.(������ȣ, ��������ġ)�� ������ȣ�� ������������ ���
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
