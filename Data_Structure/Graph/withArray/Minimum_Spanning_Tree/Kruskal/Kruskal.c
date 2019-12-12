//Kruskal �˰����� �̿��� �ּҽ���Ʈ�� ���(�迭�� ������ ��������Ʈ ���)
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

//������

//���� ����ü
struct VerticesArray {
	int vertexNum; //������ȣ
};

//��������Ʈ
struct VerticesArray* VerticesArrayList;

//���� ����ü
struct EdgesArray {
	int vertexNum1;
	int vertexNum2;
	int weight;
};

//��������Ʈ
struct EdgesArray* EdgesArrayList;

//������ ����
int n;

//������ ����
int m;

//�޼ҵ�

//���� v�� ���� w ���̿� ���Ը� ���� ������ ����, ����
//�����Ⱓ���̹Ƿ�, v�� w�� ������ ������� �ʴ´�
//�˰��� �̷л� ������ ��ȯ�ؾ� �ϳ�, ������ ����
void insertEdge(int index, int vertexNum1, int vertexNum2, int weight);

//Kruskal �˰����� �̿��� �ּҽ���Ʈ�� ���
void MST();

//������ ���Կ� ���� �迭�� ������������ ����
//�ش� �迭�� ťó�� ���
void sortQueue();


int main() {

	scanf("%d %d", &n, &m);

	//���� �� ��������Ʈ ����
	VerticesArrayList = malloc(sizeof(struct VerticesArray) * n);
	for (int i = 0; i < n; i++) {
		VerticesArrayList[i].vertexNum = (i + 1);
	}

	//���� �� ��������Ʈ ����
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

	//���� ����
	EdgesArrayList[index].vertexNum1 = vertexNum1;
	EdgesArrayList[index].vertexNum2 = vertexNum2;
	EdgesArrayList[index].weight = weight;

	return;

}//insertEdge()

void MST() {

	//1. ��� ������ ���� ������ �賶 ����(�и�����)
	int* disjointSet = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		disjointSet[i] = i + 1;
	}

	
	//2. ������ ť�� ����
	//������ ������ �ܼ�ȭ�� ���� ��������Ʈ�� ť�� �����ϰ� ������������ ����
	sortQueue();
	
	//3. ������ ���� (����-1)�� ������ ť �����ϸ鼭 MST����
	int totalWeigh = 0;
	int count = 0; //���� ���� ������ ����

	for (int i = 0; i < m; i++) {

		//�ش� ������ ������ 
		if (disjointSet[EdgesArrayList[i].vertexNum1 - 1] != disjointSet[EdgesArrayList[i].vertexNum2 - 1]) {
			printf(" %d", EdgesArrayList[i].weight);
			totalWeigh += EdgesArrayList[i].weight;

			int beforeSet = disjointSet[EdgesArrayList[i].vertexNum1 - 1]; //���� �� �Ҽ�
			int AfterSet = disjointSet[EdgesArrayList[i].vertexNum2 - 1]; //���� �� �Ҽ�
			for (int j = 0; j < n; j++) {
				if (disjointSet[j] == beforeSet) {
					disjointSet[j] = AfterSet;
				}
			}//for

			count++;
		}

		//������ ���� (����-1)�� ������
		if (count == n - 1) {
			break;
		}
	}//for
	
	printf("\n%d\n", totalWeigh);
	
}//MST()

void sortQueue() {

	//��������
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