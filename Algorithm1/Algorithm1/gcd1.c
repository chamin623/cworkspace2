#include <stdio.h>
#include <stdbool.h> // true/false
/*
	- 최대공약수(Greatest Common Divisor) 구하기
		# 계산 과정
		1. 두 수 중 더 작은 값을 i에 저장한다.
		2. I가 두 수의 공통된 약수인지 확인한다.
		3. 공통된 약수이면 이 값을 결과값으로 돌려주고 종료한다.
		4. 공통된 약수가 아니면 i를 1만큼 감소시키고, 2번으로 돌아가 반복한다.
*/
//min 정의
int min(int x, int y) {
	return (x < y) ? x : y;
}

//gcd 정의
int gcd(int a, int b) {
	int i; //두 수 중 더 작은 수 저장

	i = min(a, b);
	//printf("%d\n", i);

	while (true) {
		if (a % i == 0 && b % i == 0)
			return i;
		i--; //i를 1감소
	}
}
/*
	a=4, b=6

	i=4
	4%4==0 && 6%4==0, false

	i=3
	4%3==0 && 6%3==0, false
	
	i=2(최대공약수)
	4%2==0 && 6%2==0, true
*/
int main()
{
	printf("%d\n", gcd(4, 6)); //2
	printf("%d\n", gcd(1, 5)); //1
	printf("%d\n", gcd(60, 24)); //12

	return 0;
}