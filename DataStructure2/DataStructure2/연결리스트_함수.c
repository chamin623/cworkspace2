#include <stdio.h>
#include <stdlib.h>
/*
	동적 메모리 기반의 연결리스트 - 함수로 구현
*/
typedef struct {
	int data; //노드가 저장하는 값
	struct Node* next; //다음 요소의 주소
}Node;

//노드 생성 함수
Node* createNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		puts("메모리 할당 실패!");
		exit(1);
	}
	newNode->data = value; //데이터값 저장
	newNode -> next = NULL; //주소 초기화
	return newNode; //새 노드 반환
}

//노드의 개수 카운트 함수
int getLength(Node* head) {
	int count = 0;
	Node* current = head;
	while (current != NULL) {
		count++;
		current = current->next; //현재 노드를 다음 노드로 이동
	}
	return count;
}

//노드 출력 함수
void printList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	//printf("\n");
	puts("NULL");
}

int main()
{
	//노드 3개(동적 할당) 생성
	Node* head = createNode(10);
	Node* second = createNode(20);
	Node* third = createNode(30);

	//노드 링크
	head->next = second;
	second->next = third;

	//노드의 개수
	printf("노드의 개수: %d\n", getLength(head));

	//출력
	puts("연결리스트 출력");
	printList(head); //head 노드 입력

	//메모리 해제(큐 방식)
	//순회하는 current와, free하는 temp 따로 존재 (current는 free 되기 전에 다음으로 이동해야 함)
	Node* current = head;
	while (current != NULL) {
		Node* temp = current; //현재 노드 저장
		printf("free(%d)\n", current->data);
		current = current->next;
		free(temp); //맨처음 head 제거
	}

	return 0;
}