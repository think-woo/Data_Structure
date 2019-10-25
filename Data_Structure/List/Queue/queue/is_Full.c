//ť�� �� ���ִ��� Ȯ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct QUEUE{
	int size; //ť�� �ִ� ũ��
	int	*arr; //�ڷ����� ����� ���Ƿ� ����, �迭 ����� ����
	int front, rear; //ť�� �հ� ��
};

struct QUEUE create_queue(int maxQueueSize); //ť ����
int is_Empty(struct QUEUE *target); //ť�� ����ִ��� Ȯ��
int is_Full(struct QUEUE *target); //ť�� �� ���ִ��� Ȯ��

int main()
{
	struct QUEUE *myQueue=malloc(sizeof(struct QUEUE));

	*myQueue = create_queue(4);

	myQueue->rear=3;

	printf("%d\n", is_Full(myQueue));

	free(myQueue);
	
    return 0;

}

struct QUEUE create_queue(int maxQueueSize){

	struct QUEUE myQueue;

	myQueue.size = maxQueueSize; //ť�� �ִ�ũ�� ����
	myQueue.arr[maxQueueSize];  //ť�� �迭 ����
	myQueue.front = myQueue.rear = -1; //ť�� �հ� �� -1 �ʱ�ȭ

	return myQueue;
}

int is_empty(struct QUEUE *target){

	return (target->front == target->rear); //�հ� ���� ��ġ�� ������ ����ִ�
}

int is_Full(struct QUEUE *target){

	return (target->rear == target->size-1); //�ڸ� -1�� �ʱ�ȭ������ �ִ�ũ�⿡�� -1�� �ؾ��Ѵ�
}