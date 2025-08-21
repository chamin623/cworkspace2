#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int strLength(char* s) {
	int len = 0;

	//while (s[len] != '\0')
	while (*s++ != '\0')
		len++;
	return len; //문자열의 개수 반환
}

int main()
{
	char a[] = "DOG";
	char*b = "DOG";

	//문자열의 길이
	printf("%s %d\n", a, strlen(a));
	printf("%s %d\n", a, strlen(b));

	//인덱싱
	printf("%c\n", b[0]); //D
	printf("%c\n", b[1]); //O
	printf("%c\n", b[2]); //G

	//문자열 함수 직접 만들기
	//char str[]="monkey";
	char str[128];
	int len;

	printf("문자열 입력: ");
	scanf("%s", str);

	len = strLength(str); //문자열 길이 함수 호출
	printf("%d\n", len);

	return 0;
}