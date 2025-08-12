#include <stdio.h>
/*
	피보나치 수열
	1 1 2 3 5 8 13 ...
	셋째항 = 첫째항 + 둘째항

	메모이제이션 - 메모 기법
	- 어떤 문제에 대한 해답을 얻으면 그것을 메모해 둔다
	- 계산 복잡도 O(2^n) -> O(n)으로 변경
*/

int memo[50] = { 0 };

int fibo(int n) {
	if (memo[n] != 0)
		return memo[n]; //이미 계산되어 있으면 바로 반환
	
	if (n <= 2)
		return memo[n] = 1; //저장 후 반환
	else
		return memo[n] = fibo(n - 2) + fibo(n - 1);
}

/*
	n=n, fibo(n) fibo(n-2) + fivo(n-1)
	n=4, fibo(4) fibo(2) + fivo(3) = 3
	n=3, fibo(3) fibo(1) + fibo(2) = 2
	n=2, fibo(2) = 1
	n=1, fibo(1) = 1
*/

int func(int n) {
	if (n == 1)
		return 1;
	else
		return n*func(n-1);
}

int main()
{
	/*
	printf("%d\n", fibo(4)); //3
	printf("%d\n", fibo(3)); //2
	printf("%d\n", fibo(2)); //1
	printf("%d\n", fibo(1)); //1
	*/

	/*puts("** 1년동안의 토끼의 개체수 출력 **");
	for (int i = 1;i <= 12;i++) {
		printf("%d ", fibo(i));
	}*/

	int i;
	for (i = 5;i >= 0;i--) {
		if (i % 2 == 1)
			printf("func(%d) : %d\n", i, func(i));
	}

	return 0;
}