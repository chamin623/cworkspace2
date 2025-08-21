#include <stdio.h>
#define MAX_LEN 3

char stack[MAX_LEN]; //문자를 저장할 스택 배열
int top = -1; //맨 위 초기화

void push(char ch) {
	if (top >= MAX_LEN - 1) {
		printf("스택이 가득 찼습니다.\n");
		return;
	}
	stack[++top] = ch;
	printf("%c ", stack[top]);
}

char pop() {
	if (top < 0) {
		printf("스택이 비어 있습니다.\n");
		return  '\0'; //널문자 반환
	}
	else
		return stack[top--];
}

int main()
{
	puts("== 스택에 자료 삽입 ==");
	push('a');	//a
	push('b');	//b
	push('c');	//c
	//push('d');	//입력 초과로 실패

	//랜덤 접근 원칙적으로 사용하지 않음
	//printf("%c\n", stack[0]); //a

	puts("\n== 스택에서 자료 삭제 ==");
	/*printf("%c\n", pop());	//c
	printf("%c\n", pop());	//b
	printf("%c\n", pop());	//a
	printf("%c\n", pop());	//비었을 때 pop 시도*/

	while (top != -1) {
		printf("%c ", pop());
	}

	return 0;
}