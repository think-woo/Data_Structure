//삽입정렬 구현
#include <stdio.h>
#include <stdlib.h> //malloc(), free();

struct Array{
	int size; //배열의 크기
	int count;//현재 배열의 원소 갯수
	int *intArr; //배열. 자료형은 사용자설정.
};

void insert_by_value(struct Array *myArr, int key_element, int count); //count만큼 원소를 지닌 배열에 특정 원소를 삽입
void insertion_sort(struct Array *myArr, int count); //count만큼 원소를 지닌 배열을 삽입정렬

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

	insertion_sort(myArr, myArr->count);

	for(i=0; i<myArr->count; i++){
		printf("%d ", myArr->intArr[i]); //출력: 1 2 3 4 5 6 7
	}

	free(myArr->intArr);
	free(myArr);

	return 0;
}

void insert_by_value(struct Array *myArr, int key_element, int count){

	int i,j;

	// 1)원소 추가할 위치 찾기
	for(i=0; i<count; i++){
		if(myArr->intArr[i] > key_element){
			break;
			//그대로 원소가 저장될 위치 저장
		}
	}

	// 2)기존 원소 밀어내기
	// 이론상 j=count-1을 해야 하지만, 포인터로 구현해서 해당 범위를 초과하면 범위를 넘어선 원소도 수정되어 버림
	for(j=count-2; j>=i; j--){ 
		myArr->intArr[j+1] = myArr->intArr[j];
	}

	// 3)원소 삽입
	myArr->intArr[i] = key_element;

}


void insertion_sort(struct Array *myArr, int count){

	int i;

	for(i=1; i<count; i++){
		insert_by_value(myArr, myArr->intArr[i], i+1);
	}

}