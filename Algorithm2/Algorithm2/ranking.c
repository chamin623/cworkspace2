#include <stdio.h>
#include <stdlib.h>
/*
	���� ���ϱ�
	- �迭�� �� ��Ұ� ��� ��ҿ� ����
	- rank �迭�� 1�� �ʱ�ȭ
	- � ��Ұ� �ڱ⺸�� ũ�� rank ��Ҹ� 1 ������Ŵ
*/
int main()
{
	int arr[] = { 41, 8, 36, 77, 15 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//int rank[5];
	int* rank; //���� �Ҵ�
	int i, j;
	
	rank = (int*)malloc(sizeof(int) * size);

	//�� �� ���� ����
	for (i = 0;i < size;i++) {
		rank[i] = 1;
		for (j = 0;j < size;j++) {
			if (arr[i] < arr[j])
				rank[i] += 1;
		}
	}
	/*
		i=0, j=3, 41<77, rank[0]+=1

		i=1, j=0, 8<41, rank[1]+=1
			 j=2, 8<36, rank[1]+=1
			 j=3, 8<77, rank[1]+=1
			 j=4, 8<15, rank[1]+=1

		i=2, j=0, 36<41, rank[2]+=1 
			 j=3, 36<77, rank[2]+=1

		i=4, j=0, 15<41, rank[4]+=1
		     j=2, 15<36, rank[4]+=1
			 j=3, 15<77, rank[4]+=1
	*/
	//���� ���
	for (i = 0;i < size;i++) {
		printf("%d ", rank[i]);  //2 5 3 1 4
	}

	free(rank);

	return 0;
}