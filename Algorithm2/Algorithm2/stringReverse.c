#include <stdio.h>
#include <string.h>
/*
	문자열 거꾸로 복사
*/
int main()
{
	/*char a1[] = "DOG"; //'D', 'O', 'G', '\0' - 4개
	char a2[10]; //충분한 크기 확보
	int i;

	//a1을 a2에 거꾸로 복사하기
	for (i = 0;i < 3;i++) {
		//a2[i] = a1[i];
		a2[i] = a1[2 - i];
	}
	a2[i] = '\0'; //문자열을 복사한 후에 '\0' 추가

	printf("%s를 거꾸로 읽으면 %s\n", a1, a2);*/

	//strlen()을 사용하여 거꾸로 복사하기
	char b1[] = "DOG";
	char b2[10];
	int i;
	int n = strlen(b1); //문자의 개수

	printf("%d\n", n); //3

	for (i = n-1;i >= 0;i--) {
		b2[n - 1 - i] = b1[i];
	}
	b2[n] = '\0';

	printf("%s를 거꾸로 읽으면 %s\n", b1, b2);

	return 0;
}