//���ÿ� ���� ����, ����, ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _STACK {
	int size; //������ �ִ� ũ��
	int *arr; //������Ÿ���� ����� ���Ƿ� �����ϱ�, �迭 ����� ����
	int TOP; //top�� ��ġ
};

struct _STACK create_stack(int maxStackSize); //�ش� ũ�⸦ ���� ���� ����
int is_Empty(struct _STACK *target); //������ ����ִ��� Ȯ��
int is_Full(struct _STACK *target); //������ �����ִ��� Ȯ��
void push(struct _STACK *target, int key_element); //���ÿ� ���� ����
int pop(struct _STACK *target); //���ÿ� ���� ���� �� ���� ���� ��ȯ
int TOP(struct _STACK *target); //TOP���� ���� ����� ���� ��ȯ


int main()
{
	struct _STACK *myStack = malloc(sizeof(struct _STACK));
	int i;

	*myStack = create_stack(5);

	for(i=0; i<myStack->size; i++){ //���ÿ� ���� ����
		push(myStack, i);
	}

	printf("������ ����: %d\n", pop(myStack));
	printf("������ ����: %d\n", pop(myStack));
	printf("TOP ����: %d\n", TOP(myStack));

	free(myStack);

    return 0;

}

struct _STACK create_stack(int maxStackSize){

	struct _STACK Stack;

	Stack.size = maxStackSize;
	Stack.arr = malloc(sizeof(int)*maxStackSize);
	Stack.TOP = 0; //0���� �ʱ�ȭ�ؾ� �ε��� ������ �� �� ����

	return Stack;
}

int is_Empty(struct _STACK *target){
	return (target->TOP == 0);
}

int is_Full(struct _STACK *target){
	return (target->TOP == target->size);
}

void push(struct _STACK *target, int key_element){

	if(is_Full(target)){ //������ �� �� ������, �Լ� öȸ
		return;
	}

	target->arr[target->TOP] = key_element;
	target->TOP+=1;
}

int pop(struct _STACK *target){

	if(is_Empty(target)){ //������ ����� ��, �Լ� öȸ
		return NULL;
	}

	target->TOP-=1; //TOP�� ���� ����� ���Ҹ� ����ؾ� �Ѵ�
	return target->arr[target->TOP];

}

int TOP(struct _STACK *target){

	if(is_Empty(target)){ //������ ����� ��, �Լ� öȸ
		return NULL;
	}

	target->TOP-=1; //TOP�� ���� ����� ���Ҹ� ����ؾ� �Ѵ�
	return target->arr[target->TOP];

}