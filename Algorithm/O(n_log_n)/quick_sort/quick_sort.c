//쾌속정렬
#include <stdio.h>
#include <stdlib.h> //malloc(), free();

int split(int start, int end, struct Array *myArr); //기준값을 통해 정렬하고, 기준값을 반환한다
void quick_sort(int start, int end, struct Array *myArr); //시작값과 끝값을 통해 쾌속정렬
void swap(int *A, int *B); //배열 안의 두 원소의 위치를 바꾸는 함수

struct Array{
	int size; //배열의 크기
	int count;//현재 배열의 원소 갯수
	int *intArr; //배열. 자료형은 사용자설정.
};


int main(){

	struct Array *myArr = malloc(sizeof(struct Array));
	int i; //반복문

	//배열 설정 시작
	myArr->size=10;
	myArr->intArr = malloc(sizeof(int)*10);
	myArr->count = 7;
	for(i=0; i<myArr->count; i++){
		myArr->intArr[i] = myArr->count-i;
	}
	//배열 설정 끝 //원소 7 6 5 4 3 2 1
	
	quick_sort(0, myArr->count-1, myArr);

	for(i=0; i<myArr->count; i++){
		printf("%d ", myArr->intArr[i]); //출력: 1 2 3 4 5 6 7
	}

	free(myArr->intArr);
	free(myArr);

	return 0;
}

int split(int start, int end, struct Array *myArr){

	int pivot = start; //리스트의 첫번째 값을 기준값으로 설정한다
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
	//right가 현재 기준값이 있는 위치가 된다
	//기준값을 기준으로 왼쪽에는 기준값보다 작은 값이, 오른쪽에는 기준값보다 큰 값이 위치해있다

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
