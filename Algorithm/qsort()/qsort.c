#include <stdio.h>
#include <stdlib.h> //qsort()

int compare(const void *a, const void *b);

int main(){

	int arr[10] = {4,2,1,9,7,5,10,8,3,6};
	int i;

	// 정렬할 배열, 요소 개수, 요소 크기, 비교 함수를 넣어줌
	qsort(arr, sizeof(arr)/sizeof(int), sizeof(int), compare);

	for(i=0; i<sizeof(arr)/sizeof(int); i++){
		printf("%d ", arr[i]);
	}

	return 0;
}

int compare(const void *a, const void *b){ //오름차순

	int num1 = *(int*)a; // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int*)b;

	if(num1 > num2){
		return 1;
	}

	if(num1 < num2){
		return -1;
	}

	return 0; //num1 == num2
}

//관련내용: https://dojang.io/mod/page/view.php?id=638