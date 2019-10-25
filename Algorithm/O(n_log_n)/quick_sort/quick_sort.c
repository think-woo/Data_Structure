//�������
#include <stdio.h>
#include <stdlib.h> //malloc(), free();

int split(int start, int end, struct Array *myArr); //���ذ��� ���� �����ϰ�, ���ذ��� ��ȯ�Ѵ�
void quick_sort(int start, int end, struct Array *myArr); //���۰��� ������ ���� �������
void swap(int *A, int *B); //�迭 ���� �� ������ ��ġ�� �ٲٴ� �Լ�

struct Array{
	int size; //�迭�� ũ��
	int count;//���� �迭�� ���� ����
	int *intArr; //�迭. �ڷ����� ����ڼ���.
};


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
	
	quick_sort(0, myArr->count-1, myArr);

	for(i=0; i<myArr->count; i++){
		printf("%d ", myArr->intArr[i]); //���: 1 2 3 4 5 6 7
	}

	free(myArr->intArr);
	free(myArr);

	return 0;
}

int split(int start, int end, struct Array *myArr){

	int pivot = start; //����Ʈ�� ù��° ���� ���ذ����� �����Ѵ�
	int left = start+1;
	int right = end;

	while(left <= right){
		while(myArr->intArr[pivot] >= myArr->intArr[left] && left <= right){
			left++;
		}

		while(myArr->intArr[pivot] <= myArr->intArr[right] && left <= right){
			right--;
		}

		if(left <= right){
			swap(&myArr->intArr[left] , &myArr->intArr[right]);
		}

	}

	swap(&myArr->intArr[right] , &myArr->intArr[pivot]);

	return right;
	//right�� ���� ���ذ��� �ִ� ��ġ�� �ȴ�
	//���ذ��� �������� ���ʿ��� ���ذ����� ���� ����, �����ʿ��� ���ذ����� ū ���� ��ġ���ִ�

}
void quick_sort(int start, int end, struct Array *myArr){

	int mid;

	if(start >= end){
		return;
	}

	mid = split(start, end, myArr);
	quick_sort(start, mid-1, myArr);
	quick_sort(mid+1, end, myArr);
}

void swap(int *A, int *B){
	int temp;

	temp = *A;
	*A = *B;
	*B = temp;
}
