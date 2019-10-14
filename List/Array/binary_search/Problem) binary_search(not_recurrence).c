//(����Ž��-����͹���) ���ĵǾ� �ִ� n���� ���� Ű(����)�� Ž���� Ű k�� �Է¹޾�, �������� k�� ��ġ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <stdio.h>
#include <stdlib.h> //malloc(), free()

int notRecursiveFindElement(int intArr[], int key, int left, int right); //Ű�� k�� �����ϴ� ��ġ�� ��ȯ�ϴ� �Լ�

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

	printf("%d", notRecursiveFindElement(intArr, k, 0, n-1));

	free(intArr);

	return 0;
}

int notRecursiveFindElement(int intArr[], int k, int l, int r){

	int mid; //�迭�� �߾���ġ

	if(l > r){ //���� ��ġ�� ������ ��ġ���� ū ��� >> ����� ��Ȳ
		return -1;
	}

	//����Ž��
	while(l <= r){
		mid  = (l+r)/2;

		if(l == r){ //����Ž���� ���� ��
			if(k <= intArr[l]){ // x>=k�� ���
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