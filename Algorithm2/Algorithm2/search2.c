#include <stdio.h>

int main()
{
	int a[] = { 9, 8, 7, 6, 7 };
	int i;
	int x = 7;	//ã�� ��
	int sw = 0;	//�䱼����(����) - �߰�/�߰߸���

	//7�� �� ������ ����
	for (i = 0;i < 5;i++) {
		if (a[i] == x) {
			printf("%d �߰�!\n", x);
			sw = 1;
			break; //�߰� �� ��������
		}
	}

	if (!sw) { //sw=0
		printf("%d �߰� ����!\n", x);
	}

	return 0;
}