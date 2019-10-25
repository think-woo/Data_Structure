//���� ť ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct QUEUE{
	int size; //ť�� �ִ� ũ��
	int	*arr; //�ڷ����� ����� ���Ƿ� ����, �迭 ����� ����
	int front, rear; //ť�� �հ� ��
	int count; //ť�� ���� ���� ��
};

struct QUEUE create_queue(int maxQueueSize); //ť ����
int is_Empty(struct QUEUE *target); //ť�� ����ִ��� Ȯ��
int is_Full(struct QUEUE *target); //ť�� �� ���ִ��� Ȯ��
void en_Queue(struct QUEUE *target,int key_element); //ť ���� ���� ����
int de_Queue(struct QUEUE *target); //ť ���� ���� ���� ����
int POP(struct QUEUE *target); //ť ���� ���� ���� ��ȯ

int main()
{
	struct QUEUE *myQueue=malloc(sizeof(struct QUEUE));
	int i;

	*myQueue = create_queue(4);

	for(i=myQueue->size; i>0; i--){ //ť�� ���� ����
		en_Queue(myQueue, i);
	}

	printf("���� ť�� ������ ����: %d\n", myQueue->count);
	printf("������ ť�� ����: %d\n", de_Queue(myQueue));
	printf("������ ť�� ����: %d\n", de_Queue(myQueue));


	printf("���� ť�� ������ ����: %d\n", myQueue->count);

	free(myQueue);
	
    return 0;

}

struct QUEUE create_queue(int maxQueueSize){

	struct QUEUE myQueue;

	myQueue.size = maxQueueSize; //ť�� �ִ�ũ�� ����
	myQueue.arr = malloc(sizeof(int)*maxQueueSize);  //ť�� �迭 ����
	myQueue.front = myQueue.rear = maxQueueSize - 1; //ť�� �հ� �� n-1 �ʱ�ȭ
	myQueue.count = 0; //ť�� ���� ���� ����

	return myQueue;
}

int is_empty(struct QUEUE *target){

	return (target->count == 0);
}

int is_Full(struct QUEUE *target){

	return (target->count == target->size);
}

void en_Queue(struct QUEUE *target,int key_element){

	if(is_Full(target)){ //ť�� �� �� ������ �Լ� ���
		return;
	}

	target->rear = (target->rear+1) % target->size;
	target->arr[target->rear] = key_element;
	target->count+=1; //������ ���� ����
}

int de_Queue(struct QUEUE *target){
	
	if(is_empty(target)){ //ť�� ��� ������ �Լ� ���
		return NULL;
	}
	
	target->front = (target->front + 1) % target->size;
	target->count-=1; //������ ���� ����
	return target->arr[target->front];

}

int POP(struct QUEUE *target){

	int temp; //��� ��ġ�� ������ �ӽú���

	if(is_empty(target)){ //ť�� ��� ������ �Լ� ���
		return NULL;
	}

	temp = target->front-1;
	return target->arr[temp];
	
}
