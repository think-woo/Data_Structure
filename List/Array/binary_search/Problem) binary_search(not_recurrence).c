//(이진탐색-비재귀버전) 정렬되어 있는 n개의 정수 키(사전)와 탐색할 키 k를 입력받아, 사전에서 k의 위치를 출력하는 프로그램을 작성하시오.
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

int notRecursiveFindElement(int intArr[], int key, int left, int right); //키값 k에 대응하는 위치를 반환하는 함수

int main(){

	int *intArr; //정렬시킬 배열
	int n; //동적할당 받을 배열의 크기
	int k; //찾을 키값
	int i; //반복문에서 쓰일 값

	scanf("%d %d", &n, &k);

	intArr = malloc(sizeof(int)*n);

	for(i=0; i<n; i++){
		scanf("%d", &intArr[i]);
	}

	printf("%d", notRecursiveFindElement(intArr, k, 0, n-1));

	free(intArr);

	return 0;
}

int notRecursiveFindElement(int intArr[], int k, int l, int r){

	int mid; //배열의 중앙위치

	if(l > r){ //왼쪽 위치가 오른쪽 위치보다 큰 경우 >> 모순의 상황
		return -1;
	}

	//이진탐색
	while(l <= r){
		mid  = (l+r)/2;

		if(l == r){ //이진탐색이 멈출 때
			if(k <= intArr[l]){ // x>=k의 경우
				return l;
			}
			else{ //(k > intArr[l])
				return sizeof(intArr);
			}
		}

		if(k == intArr[mid]){
			return mid;
		}
		else if(k > intArr[mid]){
			l = mid+1;
		}
		else{ //(k < intArr[mid])
			r = mid-1;
		}
	}
}