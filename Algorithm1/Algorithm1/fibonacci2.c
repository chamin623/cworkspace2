#include <stdio.h>
/*
	�Ǻ���ġ ����
	1 1 2 3 5 8 13 ...
	��°�� = ù°�� + ��°��

	�޸������̼� - �޸� ���
	- � ������ ���� �ش��� ������ �װ��� �޸��� �д�
	- ��� ���⵵ O(2^n) -> O(n)���� ����
*/

int memo[50] = { 0 };

int fibo(int n) {
	if (memo[n] != 0)
		return memo[n]; //�̹� ���Ǿ� ������ �ٷ� ��ȯ
	
	if (n <= 2)
		return memo[n] = 1; //���� �� ��ȯ
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

	/*puts("** 1�⵿���� �䳢�� ��ü�� ��� **");
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