//큐 생성
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct QUEUE{
	int size; //큐의 최대 크기
	int	*arr; //자료형은 사용자 임의로 설정, 배열 사용은 동일
	int front, rear; //큐의 앞과 뒤
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

	myQueue.size = maxQueueSize; //큐의 최대크기 설정
	myQueue.arr[maxQueueSize];  //큐의 배열 설절
	myQueue.front = myQueue.rear = -1; //큐의 앞과 뒤 -1 초기화

	return myQueue;
}