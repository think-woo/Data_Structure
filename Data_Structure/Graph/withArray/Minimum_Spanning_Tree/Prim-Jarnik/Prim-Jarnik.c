//Prim-Jarnik �˰����� �̿��� �ּҽ���Ʈ�� ���(�迭�� ������ ��������Ʈ ���)
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

//������

//���� ����ü
struct VerticesArray {
	int vertexNum; //������ȣ
	int weight; //���� �賶 �Ȱ� �賶 ���� ���� ����
	struct VerticesArray* parent; //�賶 ���� ���� �ش� ������ �θ�����
	struct IncidenceNode* IncidenceListHead; //�ش� ������ ��������Ʈ�� ���(��)
};

//��������Ʈ
struct VerticesArray* VerticesArrayList;

//��������Ʈ
struct IncidenceNode {
	int adjacentVertexNum; //�����ϴ� ������ ��ȣ
	int adjacentVertexWeight; //�����ϴ� ������ �մ� ������ ����
	struct IncidenceNode* next; //���� ��Ź����Ʈ
};

//������ ����
int n;

//������ ����
int m;

//�޼ҵ�

//��������Ʈ ����
struct IncidenceNode* createIncidenceNode();

//���� v�� ���� w ���̿� ���Ը� ���� ������ ����, ����
//�����Ⱓ���̹Ƿ�, v�� w�� ������ ������� �ʴ´�
//�˰��� �̷л� ������ ��ȯ�ؾ� �ϳ�, ������ ����
void insertEdge(int vertexNum1, int vertexNum2, int weight);

//Prim-Jarnik �˰����� �̿��� �ּҽ���Ʈ�� ���
void MST(int startVertex);

//������ ���Կ� ���� �迭�� ������������ ����
//�ش� �迭�� ťó�� ���
void sortQueue(int startIndex);


int main() {

	scanf("%d %d", &n, &m);

	//���� �� ��������Ʈ ����
	VerticesArrayList = malloc(sizeof(struct VerticesArray) * n);
	for (int i = 0; i < n; i++) {
		VerticesArrayList[i].vertexNum = (i + 1);
		VerticesArrayList[i].IncidenceListHead = createIncidenceNode();
	}

	//���� ����
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

	//���� ����
	//������ ���� ���� ����ü�� ��������Ʈ�� �������� �ʰ�, �ٷ� �ش� ������ ��������Ʈ�� �����Ѵ�

	//ù ��° ���� ����
	struct VerticesArray* vertex1 = &VerticesArrayList[vertexNum1 - 1];
	struct IncidenceNode* newIncidence1 = createIncidenceNode();

	newIncidence1->next = vertex1->IncidenceListHead->next;
	vertex1->IncidenceListHead->next = newIncidence1;

	newIncidence1->adjacentVertexNum = vertexNum2;
	newIncidence1->adjacentVertexWeight = weight;

	//�� ��° ���� ����
	struct VerticesArray* vertex2 = &VerticesArrayList[vertexNum2 - 1];
	struct IncidenceNode* newIncidence2 = createIncidenceNode();

	newIncidence2->next = vertex2->IncidenceListHead->next;
	vertex2->IncidenceListHead->next = newIncidence2;

	newIncidence2->adjacentVertexNum = vertexNum1;
	newIncidence2->adjacentVertexWeight = weight;

	return;

}//insertEdge()

void MST(int startVertex) {

	//1. ��� ������ ���Կ� �賶 �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		VerticesArrayList[i].weight = 9999;
		VerticesArrayList[i].parent = NULL;
	}

	//2. ���� ���� ����
	struct VerticesArray* vertex = &VerticesArrayList[startVertex - 1];
	vertex->weight = 0;



	//3. ������ ���Ը� Ű������ �ϴ� ť ����
	//������ ���� ť�� �������� �ʰ� �迭�� ������ ��������Ʈ�� ť�� ����Ѵ�
	sortQueue(0);

	//4. ť�� ���Ҹ� �ϳ��� �����ϸ鼭 MST(�ּҽ���Ʈ��) ���

	int totalWeight = 0;
	for (int i = 0; i < n; i++) {

		//Ž���� ���� ���
		printf(" %d", VerticesArrayList[i].vertexNum);
		totalWeight += VerticesArrayList[i].weight;

		//�ش� ������ ������ ���� �˻�
		struct IncidenceNode* curr = VerticesArrayList[i].IncidenceListHead->next;
		while (curr != NULL) {

			for (int j = i + 1; j < n; j++) {
				if (curr->adjacentVertexNum == VerticesArrayList[j].vertexNum) { //�ش� ������ ť �ȿ� �����ϴ� ���
					if (VerticesArrayList[j].weight > curr->adjacentVertexWeight) {//�ش� ������ ���� ���԰� �賶 �Ȱ� ���� �̾��ִ� ���Ժ��� ū ���

						VerticesArrayList[j].weight = curr->adjacentVertexWeight;
						VerticesArrayList[j].parent = &VerticesArrayList[i];

						sortQueue(i + 1); //���� �ݺ������� ������ ť �ٷ� �ں��� ����

						break; //ã���� ���� ���� ������ �Ѿ�� �ȴ�
					}//if
				}//if
			}//for
			curr = curr->next;
		}//while

	}//for

	printf("\n%d", totalWeight);

}//MST()

void sortQueue(int startIndex) {

	//��������
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

