#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

//큐가 비었는지 여부
bool isEmpty(Queue* q) {
	return q->front == q->rear;
}

//큐가 가득 찼는지 여부
bool isFull(Queue* q) {
	return (q->rear + 1) % MAX_QUEUE == q->front;
	/*
	이런 방식 사용 이유 : 큐가 비었을 때와 가득 찼을 때 구분하기 위함
	(3개 넣었을 때 rear은 3)(넣을 수 있는 최대 개수는 MAX_QUEUE-1)
	비었을 때 -> (0+1)%4 == 0 -> false
	가득 찼을 때 -> (3+1)%4 == 0 -> true
	*/ 
}

//고객 추가
void enQueue(Queue* q, const char* name) {
	if (isFull(q)) {
		puts("큐가 가득 찼습니다.");
		return;
	}
	//이름을 할당할 큐 배열 생성(동적 할당)
	q->data[q->rear] = (char*)malloc(strlen(name) + 1);  //( sizeof 안해도 되는 이유: char은 1byte라 안해도 같은 byte값 나오기 때문 )
	if (q->data[q->rear] == NULL) {
		puts("메모리 할당 실패");
		exit(1);
	}
	strcpy(q->data[q->rear], name); //이름 저장
	q->rear = (q->rear + 1) % MAX_QUEUE; //rear이동
	printf("%s님이 대기열에 추가되었습니다.\n\n", name);
}

//대기열 출력
void printQueue(Queue* q) {
	if (isEmpty(q)) {
		puts("대기열이 비어 있습니다.\n");
		return;
	}
	printf("현재 대기열: ");
	int i = q->front;
	while (i != q->rear) {
		printf("[%s] ", q->data[i]); //고객 이름
		i = (i + 1) % MAX_QUEUE;
	}
	printf("\n");
}

//고객 꺼내기
int deQueue(Queue* q, char* name) {
	if (isEmpty(q)) {
		puts("큐가 비어있습니다.");
		name[0] = '\0';
		return -1;
	}
	strcpy(name, q->data[q->front]); //큐에서 꺼내온 이름 저장
	free(q->data[q->front]); //꺼낸 문자열 메모리 해제
	q->data[q->front] == NULL; //메모리 해제한 위치 초기화(안전한 사용)
	q->front = (q->front + 1) % MAX_QUEUE;
	return 0; //고객 이름을 꺼내고 메모리 해제가 성공하면  0 반환
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
		getchar(); //입력버퍼 정리

		switch (choice) {
		case 1:
			printf("고객 이름 입력: ");
			fgets(name, NAME_LEN, stdin); //공백 포함 문자 처리(fgets는 개행문자까지 읽음)
			name[strcspn(name, "\n")] = '\0'; //개행문자 -> 널문자로 바꾸기
			enQueue(&q, name); 
			break;
		case 2:
			if (deQueue(&q, name) == 0) {
				printf("%s님 업무 처리 완료\n\n", name);
			}
			break;
		case 3:
			printQueue(&q);
			break;
		case 4:
			//종료 전 남은 메모리 해제
			while (!isEmpty(&q)) {
				deQueue(&q, name);
			}
			puts("프로그램을 종료합니다.");
			run = false;
			break;
		default:
			puts("잘못된 선택입니다. 다시 입력하세요.\n");
			break;
		}
	}

	return 0;
}