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
		/*newNode->data = value;
		//기존의 head를 새 노드의 next로 가리킨 후, 새 노드를 head로 수정 -> 매번 새로 들어온게 head
		newNode->next = head;
		head = newNode;*/

		//2. 노드 생성 - 맨 뒤에 삽입
		/*newNode->data = value;
		newNode->next = NULL;

		if (head == NULL) { 
			head = newNode; //맨 첫 노드라면, 새 노드가 head가 됨
			current = newNode; //current 이동
		}
		else {
			current->next = newNode; //이미 노드 있다면, 마지막 노드에 새 노드 연결
			current = newNode; //current 이동
		}*/
	}

	puts("연결리스트 출력");
	current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	puts("NULL");

	//메모리 해제
	current = head;
	while (current != NULL) {
		Node* temp = current;
		//current: 순회용, temp: free용
		//current를 다음으로 이동한 후, temp로 free
		current = current->next;
		free(temp);
	}

	return 0;
}