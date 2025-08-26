#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 10

//노드 구조체
typedef struct Node {
	char* key; //키(문자열)
	int value; //정수값
	struct Node* next; //노드의 다음 주소
}Node;

Node* hashTable[TABLE_SIZE]; //노드를 저장할 배열

//해시 함수
unsigned int hash(const char* key) {
	unsigned int hash = 0; //hash값 누적용 변수
	while (*key) {
		hash = (hash * 31) + *key++;
	}
	return hash % TABLE_SIZE;
}

//삽입 함수
void insert(const char* key, int value) {
	unsigned int index = hash(key);
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		puts("메모리 할당 실패");
		exit(1);
	}
	newNode->key = _strdup(key); //strcpy()
	newNode->value = value;
	newNode->next = hashTable[index]; //기존 연결리스트 앞에 연결 - 충돌방지
	hashTable[index] = newNode; //세 노드를 체인 맨 앞에 등록(연결리스트)
}

//해시 테이블 출력
void printTable() {
	for (int i = 0;i < TABLE_SIZE;i++) {
		printf("[%d] ", i);
		Node* current = hashTable[i];
		while (current) {
			printf("(%s, %d) -> ", current->key, current->value);
			current = current->next; //다음 노드로 이동
		}
		printf("NULL\n");
	}
}

int main()
{
	insert("apple", 100);
	insert("banana", 200);
	insert("grape", 300);
	insert("orange", 400);
	insert("melon", 500);

	printTable();

	return 0;
}