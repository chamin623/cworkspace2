#include <stdio.h>
/*
	���� ����(Bubble Sorting)
	- �迭���� ������ �� ���� ��Ҹ� ���Ͽ� �ڸ��� �ٲٴ� ���
	- ����� ������ n���� �迭���� n-1ȸ ���ϰ� ��ȯ��
*/
int main()
{
	int arr[] = { 41, 8, 36, 77, 15 };
	int i, j, temp;

	//�񱳿� ��ȯ �ݺ�
	for (i = 0;i < 5;i++) { //��ü �񱳸� 5��
		for (j = 0;j < 4;j++) { //���� ��� ��
			if (arr[j] > arr[j + 1]) { //�� ��Ұ� �� ��Һ��� ũ�� �ڸ� �ٲ� - �������� ����
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	//���
	for (i = 0;i < 5;i++)
		printf("%d ", arr[i]);

	return 0;
}