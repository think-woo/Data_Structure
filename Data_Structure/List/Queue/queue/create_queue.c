//ť ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct QUEUE{
	int size; //ť�� �ִ� ũ��
	int	*arr; //�ڷ����� ����� ���Ƿ� ����, �迭 ����� ����
	int front, rear; //ť�� �հ� ��
};

struct QUEUE create_queue(int maxQueueSize);

int main()
{
	struct QUEUE *myQueue=malloc(sizeof(struct QUEUE));

	*myQueue = create_queue(4);

	printf("%d\n", myQueue->front);

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