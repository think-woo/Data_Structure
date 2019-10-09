//스택이 꽉차있는지 확인
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _STACK {
	int size; //스택의 최대 크기
	int *arr; //데이터타입은 사용자 임의로 설정하기, 배열 사용은 동일
	int TOP; //top의 위치
};

struct _STACK create_stack(int maxStackSize); //해당 크기를 지닌 스택 생성
int is_Full(struct _STACK *target); //스택이 꽉차있는지 확인

int main()
{
	struct _STACK *myStack = malloc(sizeof(struct _STACK));

	//printf("%d\n", sizeof(struct _STACK));

	*myStack = create_stack(2);

	myStack->TOP=3;

	printf("%d\n", is_Full(myStack));

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

int is_Full(struct _STACK *target){
	return (target->TOP == target->size);
}