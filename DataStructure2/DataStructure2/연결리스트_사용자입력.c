#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
	동적 메모리 기반의 연결리스트 - 사용자 입력
*/
typedef struct {
	int data; //노드가 저장하는 값
	struct Node* next; //다음 요소의 주소
}Node;

//init
//만들어서 연결

int main()
{
	int num; //노드의 개수
	int value; //노드의 데이터
	Node* head = NULL;		//head 노드 초기화
	Node* current = NULL;	//현재 노드(순회용)
	Node* newNode = NULL;	//새 노드(추가용)

	printf("노드 개수를 입력하세요: ");
	scanf("%d", &num);

	//입력한 개수만큼 노드 생성 및 연결 반복
	for (int i = 0;i < num;i++) {
		newNode = (Node*)malloc(sizeof(Node));

		printf("%d번째 노드 값 입력: ", i+1);
		scanf("%d", &value);

		//1. 노드 생성 - 맨 앞에 삽입
		newNode->data = value;
		newNode->next = head; //새 노드가 head와 연결됨(next가 이전꺼)
		head = newNode; //새 노드가 head가 됨 (그럼 head는 head를 가리킴?)
	}

	puts("연결리스트 출력");
	current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	puts("NULL");

	return 0;
}