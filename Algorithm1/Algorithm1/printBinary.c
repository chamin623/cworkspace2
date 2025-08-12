#include <stdio.h>

void printBin(int a) {
	if (a == 0 || a == 1)
		printf("%d", a);
	else {
		printBin(a / 2);		//몫
		printf("%d", a % 2);	//나머지
	}
}

/*
	a								몫(다음 호출),		나머지(출력)
	printBin(11), printBin(11/2),	5,			11%2	1
	printBin(5), printBin(5/2),		2,			5%2		1
	printBin(2), printBin(2/2),		1,			5%2		0
	printBin(1), printBin(1/2)?,	0?,			1%2?	1
	저장된 순서와 출력된 순서가 반대(스택메모리 사용)
*/

int main()
{
	int x = 11;

	printBin(x);

	return 0;
}