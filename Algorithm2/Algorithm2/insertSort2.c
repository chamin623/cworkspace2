#include <stdio.h>
/*
	���� ����
	- ������ ��Ҹ� �׺��� ������ �˸��� ��ġ�� �����ϴ�
	  �۾��� �ݺ��Ͽ� �����ϴ� �˰����̴�.
*/

void insertSorting(int a[], int n){
	int i, j, tmp;

	//���� ����
	//���� - i�� 1���� ����, 0�� ���ĵ� ������ ������
	for (i = 1;i < 5;i++) {
		tmp = a[i]; //�񱳴�� �����صα�

		for (j = i;j > 0 && a[j - 1] > tmp;j--) { //j�ƴ� j-1�� ��
			a[j] = a[j - 1]; //���� �ε����� ���� �ε����� ����(�� ĭ �ڷ� �б�)
		}

		a[j] = tmp; //������ ��ġ�� �񱳴�� �ֱ�
	}

}

int main()
{
	int arr[5] = { 41, 36, 8, 77, 15 };
	int i;
	int size = sizeof(arr) / sizeof(arr[0]);

	insertSorting(arr, size); //���� ���� �Լ� ȣ��

	//���� �� ���
	for (i = 0;i < 5;i++)
		printf("%d ", arr[i]);

	return 0;
}