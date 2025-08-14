#include <stdio.h>
#include <stdlib.h>
/*
	���� ���ϱ�
	- �迭�� �� ��Ұ� ��� ��ҿ� ����
	- rank �迭�� 1�� �ʱ�ȭ
	- � ��Ұ� �ڱ⺸�� ũ�� rank ��Ҹ� 1 ������Ŵ
*/

void calcRank(int a[], int rank[], int n) {
	int i, j;

	//�� �� ���� ����
	for (i = 0;i < n;i++) {
		rank[i] = 1; //�ʱ� ����
		for (j = 0;j < n;j++) {
			if (a[i] < a[j])
				rank[i] += 1;
		}
	}
}

int main()
{
	int arr[] = { 41, 8, 36, 77, 15, 60 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//int rank[5];
	int* rank; //���� �Ҵ�
	int i;

	rank = (int*)malloc(sizeof(int) * size);

	calcRank(arr, rank, size); //���� �Լ� ȣ��

	//���� ���
	for (i = 0;i < size;i++) {
		printf("%d ", rank[i]);
	}

	free(rank);

	return 0;
}