//큐가 비어 있는지 확인
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct QUEUE{
	int size; //큐의 최대 크기
	int	*arr; //자료형은 사용자 임의로 설정, 배열 사용은 동일
	int front, rear; //큐의 앞과 뒤
};

struct QUEUE create_queue(int maxQueueSize); //큐 생성
int is_empty(struct QUEUE *target); //큐가 비어있는지 확인

int main()
{
	struct QUEUE *myQueue=malloc(sizeof(struct QUEUE));

	*myQueue = create_queue(4);

	printf("%d\n", is_empty(myQueue));

	free(myQueue);
	
    return 0;

}

struct QUEUE create_queue(int maxQueueSize){

	struct QUEUE myQueue;

	myQueue.size = maxQueueSize; //큐의 최대크기 설정
	myQueue.arr[maxQueueSize];  //큐의 배열 설절
	myQueue.front = myQueue.rear = -1; //큐의 앞과 뒤 -1 초기화

	return myQueue;
}

int is_empty(struct QUEUE *target){

	return (target->front == target->rear); //앞과 뒤의 위치가 같으면 비어있다
}