//�������� ����
#include <stdio.h>
#include <stdlib.h> //malloc(), free();

struct Array{
	int size; //�迭�� ũ��
	int count;//���� �迭�� ���� ����
	int *intArr; //�迭. �ڷ����� ����ڼ���.
};

int select_min(int start, int end, struct Array *myArr); //������ ó���� ������ �ּҰ��� ã�� ��ġ�� ��ȯ
void selection_sort(struct Array *myArr, int count); //count��ŭ�� �迭�� ��������
void swap(int *a, int *b); //�迭���� ������ ��ġ�� �ٲٴ� �Լ�

int main(){

	struct Array *myArr = malloc(sizeof(struct Array));
	int i; //�ݺ���

	//�迭 ���� ����
	myArr->size=10;
	myArr->intArr = malloc(sizeof(int)*10);
	myArr->count = 7;
	for(i=0; i<myArr->count; i++){
		myArr->intArr[i] = myArr->count-i;
	}
	//�迭 ���� �� //���� 7 6 5 4 3 2 1

	selection_sort(myArr, myArr->count);

	for(i=0; i<myArr->count; i++){
		printf("%d ", myArr->intArr[i]); //���: 1 2 3 4 5 6 7
	}

	free(myArr->intArr);
	free(myArr);

	return 0;
}

void selection_sort(struct Array *myArr, int count){

	int i;
	int min_idx;

	for(i=0; i<count-1; i++){
		min_idx = select_min(i, count-1, myArr);
		swap(&myArr->intArr[i], &myArr->intArr[min_idx]);
	}

}

int select_min(int start, int end, struct Array *myArr){

	int i;
	int min_idx = start;

	for(i=start+1; i<=end; i++){
		if(myArr->intArr[i] < myArr->intArr[min_idx]){
			min_idx = i;
		}
	}

	return min_idx;
}

void swap(int *a, int *b){

	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

}