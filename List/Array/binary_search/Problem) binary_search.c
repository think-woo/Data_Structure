//(����Ž��-��͹���) ���ĵǾ� �ִ� n���� ���� Ű(����)�� Ž���� Ű k�� �Է¹޾�, �������� k�� ��ġ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

int rFindElement(int intArr[], int k, int l, int r); //Ű�� k�� �����ϴ� ��ġ�� ��ȯ�ϴ� �Լ�

int main(){

	int *intArr; //���Ľ�ų �迭
	int n; //�����Ҵ� ���� �迭�� ũ��
	int k; //ã�� Ű��
	int i; //�ݺ������� ���� ��

	scanf("%d %d", &n, &k);

	intArr = malloc(sizeof(int)*n);

	for(i=0; i<n; i++){
		scanf("%d", &intArr[i]);
	}

	printf("%d", rFindElement(intArr, k, 0, n-1));

	free(intArr);

	return 0;
}

int rFindElement(int intArr[], int k, int l, int r){

	int mid = (l+r)/2; //�迭�� �߾���ġ

	if(l > r){ //���� ��ġ�� ������ ��ġ���� ū ��� >> ����� ��Ȳ
		return -1;
	}

	if(l == r){ //�� �̻� ��Ȱ���� �ʴ� ���
		if(k == intArr[l]){ //Ű���� ����
			return l;
		}
		else if(k > intArr[l]){ //�ش� Ű���� ������, k>=x�� ���
			return l;
		}
		else{ //(k < intArr[l])
			return l-1;
		}
	}

	//����Ž��
	if(k == intArr[mid]){
		return mid;
	}
	else if(k > intArr[mid]){
		return rFindElement(intArr, k, mid+1, r);
	}
	else{ //(k < intArr[mid])
		return rFindElement(intArr, k, l, mid-1);
	}
	
}