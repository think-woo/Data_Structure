//������ �����ִ��� Ȯ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

struct _STACK {
	int size; //������ �ִ� ũ��
	int *arr; //������Ÿ���� ����� ���Ƿ� �����ϱ�, �迭 ����� ����
	int TOP; //top�� ��ġ
};

struct _STACK create_stack(int maxStackSize); //�ش� ũ�⸦ ���� ���� ����
int is_Full(struct _STACK *target); //������ �����ִ��� Ȯ��

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
	Stack.TOP = 0; //0���� �ʱ�ȭ�ؾ� �ε��� ������ �� �� ����

	return Stack;
}

int is_Full(struct _STACK *target){
	return (target->TOP == target->size);
}