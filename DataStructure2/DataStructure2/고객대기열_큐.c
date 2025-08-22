#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define MAX_QUEUE 10	//큐의 크기
#define NAME_LEN 20		//고객 이름의 최대 길이

//큐 구조체 정의
typedef struct {
	char* data[MAX_QUEUE]; //포인터 배열 생성 (문자열 10개)
	int front;
	int rear;
}Queue;

//큐 초기화
void initQueue(Queue* q) {
	q->front = 0;
	q->rear = 0;
	for (int i = 0;i < MAX_QUEUE;i++)
		q->data[i] = NULL; 
}

int main()
{
	Queue q;
	char name[NAME_LEN];
	bool run = true;
	int choice;

	initQueue(&q);

	while (run) {
		printf("=== 고객 대기열 관리 ===\n");
		printf("1. 고객 추가\n");
		printf("2. 고객 처리\n");
		printf("3. 대기열 출력\n");
		printf("4. 종료\n");
		printf("\n메뉴 선택: ");
		scanf("%d", &choice);

	}

	return 0;
}