#include <stdio.h>

int main()
{
	int a[] = { 9, 8, 7, 6, 7 };
	int i;
	int x = 7;	//찾을 값
	int sw = 0;	//토굴변수(상태) - 발견/발견못함

	//7이 몇 개인지 세기
	for (i = 0;i < 5;i++) {
		if (a[i] == x) {
			printf("%d 발견!\n", x);
			sw = 1;
			break; //발견 후 빠져나옴
		}
	}

	if (!sw) { //sw=0
		printf("%d 발견 못함!\n", x);
	}

	return 0;
}