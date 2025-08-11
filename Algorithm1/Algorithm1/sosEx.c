#include <stdio.h>
/*
	재귀(recursive) 알고리즘
	- 어떤 함수 안에서 자기 자신을 부르는 것을 말함
	- 자기 자신보다 작은 입력값으로 호출
*/

void func(int n) {
	if (n <= 0) return;
	else {
		printf("Help Me!\n");
		func(n - 1);
	}
	
	/*
		n=4, Help Me! func(3)
		n=3, Help Me! func(2)
		n=2, Help Me! func(1)
		n=1, Help Me! func(0)
		n=0, 즉시 종료
	*/

	/*printf("Help Me!\n");
	n--;

	if (n <= 0)
		return;	//종료(반환값이 없음)
	else
		func(n);*/
}

int main()
{
	int count = 4;
	func(count);

	return 0;
}