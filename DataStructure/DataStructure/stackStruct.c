#include <stdio.h>
/*
	구조체 기반의 스택 구현
*/
#define MAX_LEN 4

//스택 구조체 정의
typedef struct {
	int data[MAX_LEN]; //정수를 저장할 배열
	int top; //top 인덱스
}Stack;

//스택 초기화 함수
void initStack(Stack*s) {
	s->top = -1;
}

void push(Stack* s, int value) {
	if (s->top >= MAX_LEN - 1) { //번호가 가능한 마지막 번호라면 오류(이후 추가되어 들어가니까)
		printf("스택이 가득 찼습니다.\n");
		return;
	}
	s->data[++(s->top)] = value;
	printf("%d ", value);
}

int pop(Stack* s) {
	if (s->top < 0) {
		printf("스택이 비어 있습니다.\n");
		return -1;
	}
	else
		return s->data[(s->top)--];
}

void printStack(Stack* s) {
	printf("\n현재 스택의 상태: \n");
	if (s->top == -1) {
		printf("(비어 있음)\n");
	}
	else {

		printf("남은 요소의 수: %d\n", (s->top) + 1);
		for (int i = 0;i <= s->top;i++) {
			printf("%d\n", s->data[i]);
		}
	}
}

int main()
{
	Stack stack; //구조체 변수 생성
	
	initStack(&stack); //주소를 전달
	
	puts("== 스택에 자료 삽입 ==");
	push(&stack, 80);
	push(&stack, 70);
	push(&stack, 95);
	push(&stack, 85);
	//push(&stack, 100);

	puts("\n== 스택에서 자료 삭제 ==");
	while (stack.top != -1) {
		printf("%d ", pop(&stack));
	}

	//스택의 최종 상태 출력
	printStack(&stack);

	return 0;
}