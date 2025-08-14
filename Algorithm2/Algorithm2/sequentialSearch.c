#include <stdio.h>
/*
	순차 탐색(Sequential Search)
	- 배열의 첫번재 요소부터 하나씩 검사
	- 찾는 값과 같으면 위치 출력
*/
int main()
{
	int a[9] = { 5, 9, 2, 4, 8, 6, 7, 1, 3 };
	int i;
	int x = 10; //찾을 값
	int found = 0; //상태(토굴)

	//반복 - 탐색
	for (i = 0;i < 9;i++) {
		if (a[i] == x) {
			printf("%d는(은) a[%d]에 있습니다.\n", x, i);
			found = 1;
			break;
		}
	}

	if (!found)
		printf("%d는(은) 없습니다.\n", x);

	return 0;
}