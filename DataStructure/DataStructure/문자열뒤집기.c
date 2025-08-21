//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
///*
//	스택을 응용한 문자열 역순 처리
//*/
//#define MAX_LEN 128
//typedef struct {
//	char data[MAX_LEN]; //문자열 저장할 배열
//	int top; //top 인덱스
//}Stack;
//
//void initStack(Stack* s) {
//	s->top = -1;
//}
//
//void push(Stack* s, char ch) {
//	if (s->top >= MAX_LEN - 1) {
//		printf("스택이 가득 찼습니다.\n");
//		return;
//	}
//	else
//		s->data[++(s->top)] = ch;
//}
//
//int pop(Stack* s) { //int > char(자동 형변환)
//	if (s->top < 0){
//		printf("스택이 비어 있습니다.\n");
//		return -1;
//	}
//	else {
//		return s->data[(s->top)--];
//	}
//}
//
//int main()
//{
//	Stack stack;
//	char str[MAX_LEN]; //문자열을 저장할 배열
//
//	initStack(&stack);
//	
//	//사용자 입력
//	printf("문자열 입력: ");
//	//scanf("%s", str);
//	//gets_s(str, MAX_LEN);
//	//fgets(배열, 배열의 크기, 입력스트림), 모니터에 출력-stdout
//	fgets(str, MAX_LEN, stdin); //공백문자 포함 입력 가능
//
//	//push - 문자열을 한 글자씩 넣음
//	for(int i=0;str[i]!='\0';i++)
//		push(&stack, str[i]);
//
//	//pop - 뒤집어서 출력
//	printf("뒤집은 문자열: ");
//	while (stack.top != -1) {
//		printf("%c", pop(&stack));
//	}
//
//	return 0;
//}