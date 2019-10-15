//선택정렬 구현
#include <stdio.h>
#include <stdlib.h> //malloc(), free();

struct Array{
	int size; //배열의 크기
	int count;//현재 배열의 원소 갯수
	int *intArr; //배열. 자료형은 사용자설정.
};

int select_min(int start, int end, struct Array *myArr); //설정한 처음과 끝에서 최소값을 찾아 위치를 반환
void selection_sort(struct Array *myArr, int count); //count만큼의 배열을 선택정렬
void swap(int *a, int *b); //배열에서 원소의 위치를 바꾸는 함수

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

	selection_sort(myArr, myArr->count);

	for(i=0; i<myArr->count; i++){
		printf("%d ", myArr->intArr[i]); //출력: 1 2 3 4 5 6 7
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