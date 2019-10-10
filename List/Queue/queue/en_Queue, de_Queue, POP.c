//큐 원소의 삽입, 제거, 반환
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct QUEUE{
	int size; //큐의 최대 크기
	int	*arr; //자료형은 사용자 임의로 설정, 배열 사용은 동일
	int front, rear; //큐의 앞과 뒤
};

struct QUEUE create_queue(int maxQueueSize); //큐 생성
int is_Empty(struct QUEUE *target); //큐가 비어있는지 확인
int is_Full(struct QUEUE *target); //큐가 꽉 차있는지 확인
void en_Queue(struct QUEUE *target,int key_element); //큐 뒤의 원소 삽입
int de_Queue(struct QUEUE *target); //큐 가장 앞의 원소 제거
int POP(struct QUEUE *target); //큐 가장 앞의 원소 반환

int main()
{
	struct QUEUE *myQueue=malloc(sizeof(struct QUEUE));
	int i;

	*myQueue = create_queue(4);

	for(i=myQueue->size; i>0; i--){ //큐에 원소 삽입
		en_Queue(myQueue, i);
	}

	printf("큐의 가장 앞의 원소 삭제: %d\n", de_Queue(myQueue));
	printf("남아 있는 큐의 가장 앞의 원소: %d\n", POP(myQueue));

	free(myQueue);
	
    return 0;

}

struct QUEUE create_queue(int maxQueueSize){

	struct QUEUE myQueue;

	myQueue.size = maxQueueSize; //큐의 최대크기 설정
	myQueue.arr = malloc(sizeof(int)*maxQueueSize);  //큐의 배열 설절
	myQueue.front = myQueue.rear = -1; //큐의 앞과 뒤 -1 초기화

	return myQueue;
}

int is_empty(struct QUEUE *target){

	return (target->front == target->rear); //앞과 뒤의 위치가 같으면 비어있다
}

int is_Full(struct QUEUE *target){

	return (target->rear == target->size-1); //뒤를 -1로 초기화했으니 최대크기에서 -1을 해야한다
}

void en_Queue(struct QUEUE *target,int key_element){

	if(is_Full(target)){ //큐가 꽉 차 있으면 함수 취소
		return;
	}

	target->rear+=1;
	target->arr[target->rear] = key_element; //rear를 1 올리고 원소 삽입
}

int de_Queue(struct QUEUE *target){
	
	if(is_empty(target)){ //큐가 비어 있으면 함수 취소
		return NULL;
	}
	
	target->front+=1;
	return target->arr[target->front]; //front를 1올리고 원소 삽입

}

int POP(struct QUEUE *target){

	if(is_empty(target)){ //큐가 비어 있으면 함수 취소
		return NULL;
	}

	target->front+=1;
	return target->arr[target->front];
	
}
