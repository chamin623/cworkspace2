#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> //strcpy()
#include <stdbool.h> //bool - true/false
#include <stdlib.h> //malloc(), free()
/*
	Queue를 활용한 고객대기열 프로그램

	char str[][10] = {"고객A", "고객B", "고객C"};
	char* str[] = {"고객A", "고객B", "고객C"};

	char str[2] = "고객A";
	char* name = "고객B";

	queue[0] = {'고', '객', 'A', '\0'}
	queue[1] = {'고', '객', 'B', '\0'}
	queue[2] = {'고', '객', 'C', '\0'}
	queue[3] = {?, ?, ?}
*/
#define MAX_QUEUE 4 //최대 3명
#define NAME_LEN 20

//전역 변수
char* queue[MAX_QUEUE]; //포인터 배열
int front = 0;
int rear = 0;

//큐가 비어있는지 확인
bool isEmpty() {
	return front == rear; //참(true), 거짓(false)
}

//큐가 가득 찼는지 확인
int isFull() {
	return (rear + 1) % MAX_QUEUE == front;
}

void enQueue(const char* name) {
	if (isFull()) {
		puts("큐가 가득 찼습니다.");
		return;
	}
	//문자열 길이만큼 메모리 동적 할당
	queue[rear] = (char*)malloc(strlen(name) + 1); //+1이 널문자 추가
	if (queue[rear] == NULL) {
		printf("메모리 할당 실패!\n");
		exit(1);
	}
	strcpy(queue[rear], name);
	rear = (rear + 1) % MAX_QUEUE;
}

int deQueue(char* name) {
	if (isEmpty()) {
		puts("큐가 비었습니다.");
		name[0] = '\0'; //name을 빈 문자로 초기화
		return -1; //실패
	}
	strcpy(name, queue[front]); //문자열 꺼내서 저장
	free(queue[front]); //메모리 해제
	queue[front] = NULL; //배열을 안전하게 초기화
	front = (front + 1) % MAX_QUEUE;
}

int main()
{
	char customer[NAME_LEN]; //큐에서 꺼낸 이름

	//고객 대기열 추가
	enQueue("고객A");
	enQueue("고객B");
	enQueue("고객C");

	//대기열 처리
	while (!isEmpty()) {
		deQueue(customer);
		printf("%s님 업무 처리중...\n", customer);
	}
	puts("모든 고객의 업무가 완료되었습니다.");

	return 0;
}