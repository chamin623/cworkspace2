#include <stdio.h>

int main()
{
	//���ĵ� �迭
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int low, high, mid;
	int x; //ã�� ��
	int found; //����(�䱼) (ã��/��ã��)

	low = 0;	//ù �ε���
	high = 8;	//������ �ε���
	x = 10;
	found = 0;

	while (low<=high) {
		//�߰� �ε���
		mid = (low + high) / 2;
		//printf("%d\n", mid);
		
		if (arr[mid] == x) {
			printf("%d��(��) a[%d]�� �ֽ��ϴ�.\n", x, mid);
			found = 1;
			break;
		}

		else if (arr[mid] < x) {
			low = mid + 1;
		}

		else {
			high = mid - 1;
		}
	}
	/*
		low=0, high=8
		mid=4, 5<8, �ε��� -> low=5, high=8, mid=6
		mid=6, 7<8, �ε��� -> low=7, high=8, mid=7
		mid=7, 8=8, ã��
	*/
	if (!found)
		printf("%d��(��) �����ϴ�.\n", x);

	return 0;
}