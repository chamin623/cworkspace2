#include <stdio.h>
/*
	곱셈 알고리즘 -> 팩토리얼(재귀)
	1부터 5까지 곱하기
	1 x 2 x 3 x 4 x 5 -> 5!
	계산 복잡도
	- 곱셈 알고리즘 : n번 곱하기 - O(n)
	- 재귀 알고리즘(팩토리얼)
*/
int gobN(int n) {
	int num = 1; //곱한 결과값
	int i;
	
	for (i = 1;i <= n;i++) {
		num *= i;
	}

	return num;
}

int factorial(int n) {
	if (n <= 0)
		return 1;
	else
		return n * factorial(n - 1);
}
/*
		n! = n x (n-1)!
		...
		5! = 5x4! = 5x(5-1)!
		4! = 4x3! = 4x(4-1)!
		3! = 3x2! = 3x(3-1)!
		2! = 2x1! = 2x(2-1)!
		1! = 1 
	n=0 0! = 1 (종료 조건)
*/

int main()
{
	int value1;

	value1 = gobN(5);
	printf("결과값: %d\n", value1);

	int a, b, c;

	a = factorial(1);
	b = factorial(3);
	c = factorial(5);

	printf("1!=%d, 3!=%d, 5!=%d\n", a, b, c);

	return 0;
}