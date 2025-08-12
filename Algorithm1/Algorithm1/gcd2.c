#include <stdio.h>
#include <stdbool.h> // true/false
/*
	- 최대공약수(Greatest Common Divisor) 구하기
		# 유클리드 알고리즘
		a와 b의 최대공약수는 'b'와 'a를 b로 나눈 나머지'의 최대공약수와 같다.
		어떤 수와 0의 최대공약수는 자기 자신이다. 즉, gcd(n, 0) = n이다.
*/

//gcd 정의
int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
/*
	a=60, b=24
	gcd(60, 24) = gcd(24, 60%24) = gcd(12, 24%12) = gcd(12, 0) = 12

	a=81, b=27
	gcd(81, 27) = gcd(27, 81%27) = gcd(27, 0) = 27

*/
int main()
{
	/*
	printf("%d\n", gcd(4, 6)); //2
	printf("%d\n", gcd(1, 5)); //1
	printf("%d\n", gcd(60, 24)); //12
	printf("%d\n", gcd(81, 27)); //27
	*/

	//사용자 입력
	int x, y;
	puts("두 수의 최대공약수를 구합니다.");
	printf("첫번째 정수 입력: ");
	scanf_s("%d", &x);
	printf("두번째 정수 입력: ");
	scanf_s("%d", &y);

	printf("최대공약수는 %d입니다.\n", gcd(x, y));

	return 0;
}