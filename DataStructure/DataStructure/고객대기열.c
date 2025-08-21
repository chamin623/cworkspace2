#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
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
char queue[MAX_QUEUE][NAME_LEN]; //이차원 배열 생성
int front = 0;
int rear = 0;

//큐가 비어있는지 확인
int isEmpty() { 
	return front == rear; //참(1), 거짓(0)
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
	strcpy(queue[rear], name); //뒤쪽에서 고객 이름 저장(추가)
	rear = (rear + 1) % MAX_QUEUE;
}

int deQueue(char* name) {
	if (isEmpty()) {
		puts("큐가 비었습니다.");
		name[0] = '\0'; //name을 빈 문자로 초기화
		return -1; //실패
	}
	strcpy(name, queue[front]);
	front = (front + 1) % MAX_QUEUE;
	return 0; //성공
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