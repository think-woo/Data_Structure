//ť ������ ����, ����, ��ȯ
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

	printf("ť�� ���� ���� ���� ����: %d\n", de_Queue(myQueue));
	printf("���� �ִ� ť�� ���� ���� ����: %d\n", POP(myQueue));

	free(myQueue);
	
    return 0;

}

struct QUEUE create_queue(int maxQueueSize){

	struct QUEUE myQueue;

	myQueue.size = maxQueueSize; //ť�� �ִ�ũ�� ����
	myQueue.arr = malloc(sizeof(int)*maxQueueSize);  //ť�� �迭 ����
	myQueue.front = myQueue.rear = -1; //ť�� �հ� �� -1 �ʱ�ȭ

	return myQueue;
}

int is_empty(struct QUEUE *target){

	return (target->front == target->rear); //�հ� ���� ��ġ�� ������ ����ִ�
}

int is_Full(struct QUEUE *target){

	return (target->rear == target->size-1); //�ڸ� -1�� �ʱ�ȭ������ �ִ�ũ�⿡�� -1�� �ؾ��Ѵ�
}

void en_Queue(struct QUEUE *target,int key_element){

	if(is_Full(target)){ //ť�� �� �� ������ �Լ� ���
		return;
	}

	target->rear+=1;
	target->arr[target->rear] = key_element; //rear�� 1 �ø��� ���� ����
}

int de_Queue(struct QUEUE *target){
	
	if(is_empty(target)){ //ť�� ��� ������ �Լ� ���
		return NULL;
	}
	
	target->front+=1;
	return target->arr[target->front]; //front�� 1�ø��� ���� ����

}

int POP(struct QUEUE *target){

	if(is_empty(target)){ //ť�� ��� ������ �Լ� ���
		return NULL;
	}

	target->front+=1;
	return target->arr[target->front];
	
}
