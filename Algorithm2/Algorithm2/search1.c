#include <stdio.h>

int main()
{
	int a[] = { 9, 8, 7, 6, 7 };
	int i;
	int x = 7; //찾을 값
	int count = 0;

	//7이 몇 개인지 세기
	for (i = 0;i < 5;i++) {
		if (a[i] == x) {
			printf("%d 발견!\n", x);
			count++;
		}
	}
	printf("%d을(를) %d개 발견!\n", x, count);

	return 0;
}