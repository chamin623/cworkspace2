//CircularQueue.c - 함수의 구현부
#include <stdio.h>
#include <stdbool.h>
#include "CircularQueue.h"
/*
	구조체 기반의 원형 큐
*/

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
	printf("큐 상태: ");
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