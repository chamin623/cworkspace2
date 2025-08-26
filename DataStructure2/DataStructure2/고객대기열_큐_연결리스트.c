//( 큐가 대빵, 노드는 도구) ( 큐 멤버의 자료형도 다 노드)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20		//고객 이름의 최대 길이

//고객 노드
typedef struct Node{
	char name[NAME_LEN]; //고객 이름
	struct Node* next;	 //다음 노드의 주소
}Node;

//대기열 구조체(큐)
typedef struct {
	Node* front; //큐의 맨 앞
	Node* rear;  //큐의 맨 뒤
}Queue;

//큐 초기화
void initQueue(Queue* q) {
	q->front = NULL;
	q->rear = NULL;
}

//큐가 비어있는지 확인
bool isEmpty(Queue* q) {
	return q->front == NULL;
}

//고객 추가
void enQueue(Queue* q, const char* name) {
	Node* newNode = (Node*)malloc(sizeof(Node)); //노드 생성
	if (newNode == NULL) {
		puts("메모리 할당 실패");
		exit(1);
	}
	strcpy(newNode->name, name);
	newNode->next = NULL;

	if (isEmpty(q)) { //연결리스트의 head
		q->front = newNode;
		q->rear = newNode;
	}
	else {
		q->rear->next = newNode; //새 노드를 맨 뒤 노드의 다음으로 연결
		q->rear = newNode; //새 노드가 맨 뒤
	}
	printf("%s님이 대기열에 추가되었습니다.\n\n", name);
}

//고객 처리(제거 순서: 큐 방식)
int deQueue(Queue* q, char* name) {
	if (isEmpty(q)) {
		puts("큐가 비어있습니다.");
		name[0] = '\0';
		return -1;
	}
	Node* temp = q->front;
	strcpy(name, temp->name); //제거할 name 복사
	q->front = q->front->next; //두번째 노드가 head가 됨
	if (q->front == NULL) { //만약 마지막 노드 제거라면, rear도 NULL로 초기화
		q->rear = NULL;
	}
	free(temp); //복사해뒀으니까 첫 노드를 temp로 반환
	return 0;
}
//고객 대기열 출력
void printQueue(Queue* q) {
	if (isEmpty(q)) {
		puts("대기열이 비어 있습니다.\n");
		return;
	}
	printf("현재 대기열: ");
	Node* current = q->front;
	while (current != NULL) {
		printf("[\%s] ", current->name);
		current = current->next;
	}
	printf("\n\n");
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