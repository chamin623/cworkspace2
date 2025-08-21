#include <stdio.h>
/*
	구조체 배열의 삭제와 이동
*/

//학생 구조체 정의
typedef struct {
	int num; //번호
}Student;

int main()
{
	Student st[10]; //구조체 배열 생성
	int i;

	for (i = 0;i < 10;i++) {
		st[i].num = i + 1; //1~10까지 저장
	}

	//출력
	for (i = 0;i < 10;i++) {
		printf("%d ", st[i].num);
	}
	printf("\n");

	puts("4번 학생 전학");
	st[3].num = 0; //초기화

	puts("방을 왼쪽으로 이동");
	for (i = 3;i < 9;i++) {
		st[i].num = st[i + 1].num;
	}
	st[9].num = 0; //마지막 인덱스 초기화

	//출력
	for (i = 0;i < 10;i++) {
		printf("%d ", st[i].num);
	}
	printf("\n");

	return 0;
}