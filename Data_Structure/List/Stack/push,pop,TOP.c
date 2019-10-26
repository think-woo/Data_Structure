//스택에 원소 삽입, 삭제, 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _STACK {
	int size; //스택의 최대 크기
	int *arr; //데이터타입은 사용자 임의로 설정하기, 배열 사용은 동일
	int TOP; //top의 위치
};

struct _STACK create_stack(int maxStackSize); //해당 크기를 지닌 스택 생성
int is_Empty(struct _STACK *target); //스택이 비어있는지 확인
int is_Full(struct _STACK *target); //스택이 꽉차있는지 확인
void push(struct _STACK *target, int key_element); //스택에 원소 삽입
int pop(struct _STACK *target); //스택에 원소 삭제 및 삭제 원소 반환
int TOP(struct _STACK *target); //TOP에서 가장 가까운 원소 반환


int main()
{
	struct _STACK *myStack = malloc(sizeof(struct _STACK));
	int i;

	*myStack = create_stack(5);

	for(i=0; i<myStack->size; i++){ //스택에 원소 삽입
		push(myStack, i);
	}

	printf("삭제한 원소: %d\n", pop(myStack));
	printf("삭제한 원소: %d\n", pop(myStack));
	printf("TOP 원소: %d\n", TOP(myStack));

	free(myStack);

    return 0;

}

struct _STACK create_stack(int maxStackSize){

	struct _STACK Stack;

	Stack.size = maxStackSize;
	Stack.arr = malloc(sizeof(int)*maxStackSize);
	Stack.TOP = 0; //0으로 초기화해야 인덱스 역할을 할 수 있음

	return Stack;
}

int is_Empty(struct _STACK *target){
	return (target->TOP == 0);
}

int is_Full(struct _STACK *target){
	return (target->TOP == target->size);
}

void push(struct _STACK *target, int key_element){

	if(is_Full(target)){ //스택이 꽉 차 있을시, 함수 철회
		return;
	}

	target->arr[target->TOP] = key_element;
	target->TOP+=1;
}

int pop(struct _STACK *target){

	if(is_Empty(target)){ //스택이 비었을 시, 함수 철회
		return NULL;
	}

	target->TOP-=1; //TOP과 가장 가까운 원소를 출력해야 한다
	return target->arr[target->TOP];

}

int TOP(struct _STACK *target){

	if(is_Empty(target)){ //스택이 비었을 시, 함수 철회
		return NULL;
	}

	target->TOP-=1; //TOP과 가장 가까운 원소를 출력해야 한다
	return target->arr[target->TOP];

}