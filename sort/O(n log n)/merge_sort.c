//합병정렬
#include <stdio.h>
#include <stdlib.h> //malloc(), free();

void merge_sort(struct Array *myArr, int start, int end); //처음과 끝을 매개변수로 사용하는 분할
void merge(struct Array *myArr, int left_start, int left_end, int right_start, int right_end); //분할된 두 리스트를 정렬하고 합병

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
	

	merge_sort(myArr,0, myArr->count-1);

	for(i=0; i<myArr->count; i++){
		printf("%d ", myArr->intArr[i]); //출력: 1 2 3 4 5 6 7
	}

	free(myArr->intArr);
	free(myArr);

	return 0;
}

void merge_sort(struct Array *myArr, int start, int end){

	int mid = (start + end)/2;

	//더 이상 분할되지 않는 경우
	if(start == end){
		return;
	}
	merge_sort(myArr, start, mid);
	merge_sort(myArr, mid+1, end);
	merge(myArr, start, mid, mid+1, end);

}

void merge(struct Array *myArr, int left_start, int left_end, int right_start, int right_end){

	int lptr = left_start, rptr = right_start, temp_start = 0;
	int size = (left_end - left_start + 1) + (right_end - right_start + 1); //부분 배열의 크기
	int *temp = malloc(sizeof(int) * size); //부분 배열 생성
	int i,j; //반복문

	//두 배열 중에서 가장 작은 원소를 임시 배열에 차례대로 저장
	while(lptr <= left_end && rptr <= right_end){
		if(myArr->intArr[lptr] < myArr->intArr[rptr]){
			temp[temp_start++] = myArr->intArr[lptr++];
		}
		else{
			temp[temp_start++] = myArr->intArr[rptr++];
		}
	}

	//한 쪽 배열의 저장이 먼저 끝나면, 나머지 배열의 원소를 임시배열에 차례대로 저장
	if(lptr > left_end){
		for(i=rptr; i<= right_end; i++){
			temp[temp_start++] = myArr->intArr[i];
		}
	}
	if(rptr > right_end){
		for(i=lptr; i<= left_end; i++){
			temp[temp_start++] = myArr->intArr[i];
		}
	}

	//임시배열의 원소를 원배열에 저장
	for(i=left_start, j=0; i<right_end, j<size; i++, j++){
		myArr->intArr[i] = temp[j];
	}

	free(temp);
}
