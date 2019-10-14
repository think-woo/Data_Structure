//(이진탐색 응용) 세종이는 친구와 이진탐색을 응용한 숫자 맞추기 게임을 하고 있다. 세종이를 도와 정답을 찾는 프로그램을 작성하시오.
#include <stdio.h>
#include <stdlib.h>

int findElement(int left, int right, char *hint); //힌트를 받아 이진탐색을 하는 함수

int main(){

	int a, b; //정수 범위
	int n; //입력할 N/Y의 갯수
	int i; //반복문
	char *hint; //N/Y를 입력받을 문자열

	scanf("%d %d %d", &a, &b, &n);

	getchar();

	//문자열 할당
	hint = malloc(sizeof(char)*(n+1));
	for(i=0; i<n; i++){
		scanf("%c", &hint[i]);
	}
	hint[n] = NULL;

	printf("%d\n", findElement(a, b, hint));

	free(hint);

	return 0;
}

int findElement(int left, int right, char *hint){

	int mid = (left + right) / 2;

	if(left == right){ //탐색 종결 조건
		return left; //Key
	}

	if(*hint == 'N'){
		return findElement(left, mid, (hint+1));
	}
	else{ //(*hint == 'Y'){
		return findElement(mid+1, right, (hint+1));
	}
}