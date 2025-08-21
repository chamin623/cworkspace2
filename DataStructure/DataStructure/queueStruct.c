#include <stdio.h>
#include <stdbool.h>
/*
	구조체 기반의 원형 큐
*/
#define QUEUE_SIZE 10

typedef struct {
	int data[QUEUE_SIZE];
	int front;
	int rear;
}CircularQueue;

bool isEmpty(CircularQueue* q) {
	return q->front == q->rear;
}

bool isFull(CircularQueue* q) {
	return (q->rear + 1) % QUEUE_SIZE == q->front;
}

void initQueue(CircularQueue* q) {
	q->front = 0;
	q->rear = 0;
}

void enQueue(CircularQueue* q, int value) {
	if (isFull(q)) {
		puts("큐가 가득 찼습니다.");
		return;
	}

	q->data[q->rear] = value;
	q->rear = ((q->rear) + 1) % QUEUE_SIZE;
}

int deQueue(CircularQueue* q) {
	if (isEmpty(q)) {
		puts("큐가 비었습니다.");
		return;
	}
	int value; //큐에서 꺼낸 요소값
	value = q->data[q->front];
	q->front = ((q->front + 1) % QUEUE_SIZE);
	return value;
}

void printQueue(CircularQueue* q) {
	printf("\n큐 상태: ");
	if (isEmpty(q)) {
		puts("(비어있음)");
		return;
	}
	int i; //인덱스
	i = q->front;
	while (i != q->rear) {
		printf("%d ", q->data[i]);
		i = (i + 1) % QUEUE_SIZE;
	}
	puts("\n");
}

int main()
{
	CircularQueue q1; //구조체 변수
	CircularQueue q2;

	//큐 초기화 함수 호출
	initQueue(&q1);
	initQueue(&q2);

	puts("=== 큐1에 데이터 넣기 ===");
	enQueue(&q1, 10);
	enQueue(&q1, 20);
	enQueue(&q1, 30);
	printQueue(&q1);

	puts("=== 큐1에서 데이터 꺼내기 ===");
	printf("%d ", deQueue(&q1));
	printf("%d ", deQueue(&q1));
	printf("%d ", deQueue(&q1));
	printQueue(&q1);

	puts("=== 큐2에 데이터 넣기 ===");
	enQueue(&q2, 10);
	enQueue(&q2, 200);
	printQueue(&q2);

	return 0;
}