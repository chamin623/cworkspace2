#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int data; //노드가 저장하는 값
	struct Node* next; //다음 노드의 주소(자기 참조)
}Node;

//전역 변수
Node* head = NULL; //리스트의 시작 노드

//함수의 원형 선언
void insertNodeEnd(int value);
void printNode();
void insertNodeFront(int value);
void deleteNode(int value);
void freeList(); //동적 메모리 해제

int main()
{
	bool run = true;
	int choice; //선택 메뉴
	int value; //입력할 값

	while (run) {
		printf("=== 연결 리스트 메뉴 ===\n");
		printf("1. 맨 뒤에 노드 삽입\n");
		printf("2. 맨 앞에 노드 삽입\n");
		printf("3. 노드 삭제\n");
		printf("4. 리스트 출력\n");
		printf("5.종료\n");
		printf("\n메뉴 선택: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("삽입할 값 입력: ");
			scanf("%d", &value);
			insertNodeEnd(value);
			break;
		case 2:
			printf("삽입할 값 입력: ");
			scanf("%d", &value);
			insertNodeFront(value);
			break;
		case 3:
			printf("삭제할 값 입력: ");
			scanf("%d", &value);
			deleteNode(value);
			break;
		case 4:
			printNode();
			break;
		case 5:
			puts("프로그램 종료");
			freeList();
			run = false;
			break;
		default:
			puts("잘못된 선택입니다. 다시 입력하세요.\n");
			break;
		}
	}

	return 0;
}

void insertNodeEnd(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		puts("메모리 할당 실패!");
		return;
	}

	newNode->data = value;
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
	}
	else {
		Node* current = head;
		while (current->next != NULL) { //( current를 맨 끝으로 이동(NULL까지는 가면 안됨) )
			current = current->next;
		}
		current->next = newNode;
		//( current=current->next; //current 이동할 필요 없음. while 있으니까 )
	}
	printf("%d 맨 뒤 삽입 완료\n\n", value);
}

void printNode() {
	if (head == NULL) {
		printf("리스트가 비어 있습니다.\n\n");
		return;
	}

	Node* current = head;
	printf("리스트: ");
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	puts("NULL\n");
}

void insertNodeFront(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		puts("메모리 할당 실패!");
		return;
	}

	newNode->data = value;
	newNode->next = head;
	head = newNode;
	printf("%d 맨 앞 삽입 완료\n\n", value);
}

void deleteNode(int value) {
	Node* current = head;
	Node* prev = NULL;

	//노드 탐색 - 삭제 노드 찾기 전
	while (current != NULL&&current->data!=value) {
		prev = current;
		current = current->next;
	}

	if (current == NULL) {
		printf("%d 값이 리스트에 없습니다.\n\n", value);
		return;
	}

	//노드 삭제
	if (prev == NULL) { //첫 노드 삭제
		head = current->next; //다음 노드를 head가 됨
	}
	else {
		prev->next = current->next; //이전 노드에 현재 노드의 다음 노드가 연결
	}

	free(current); //현재 노드(삭제 노드)의 메모리 해제
	printf("%d 삭제 완료\n\n", value);
}

void freeList() {
	Node* current = head;
	while (current != NULL) {
		Node* temp = current; //현재 노드를 임시 노드에 저장
		current = current->next; //( temp로 메모리 해제 전 current 이동시켜두기 )
		free(temp);
	}
	head = NULL;
}