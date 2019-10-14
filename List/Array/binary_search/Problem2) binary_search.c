//(����Ž�� ����) �����̴� ģ���� ����Ž���� ������ ���� ���߱� ������ �ϰ� �ִ�. �����̸� ���� ������ ã�� ���α׷��� �ۼ��Ͻÿ�.
#include <stdio.h>
#include <stdlib.h>

int findElement(int left, int right, char *hint); //��Ʈ�� �޾� ����Ž���� �ϴ� �Լ�

int main(){

	int a, b; //���� ����
	int n; //�Է��� N/Y�� ����
	int i; //�ݺ���
	char *hint; //N/Y�� �Է¹��� ���ڿ�

	scanf("%d %d %d", &a, &b, &n);

	getchar();

	//���ڿ� �Ҵ�
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

	if(left == right){ //Ž�� ���� ����
		return left; //Key
	}

	if(*hint == 'N'){
		return findElement(left, mid, (hint+1));
	}
	else{ //(*hint == 'Y'){
		return findElement(mid+1, right, (hint+1));
	}
}