//CircularQueue.h - 구조체, 함수 선언부
#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H //구조체 이름 중복 사용 방지

#include <stdbool.h>
/*
	구조체 기반의 원형 큐
*/
#define QUEUE_SIZE 10

//큐 구조체 정의
typedef struct {
	int data[QUEUE_SIZE];
	int front;
	int rear;
}CircularQueue;

void initQueue(CircularQueue* q); //큐 초기화

bool isEmpty(CircularQueue* q); //큐 비어있는지 여부

bool isFull(CircularQueue* q); //큐 차있는지 여부

void enQueue(CircularQueue* q, int value); //큐에 데이터 넣기

int deQueue(CircularQueue* q); //큐에서 데이터 꺼내기

void printQueue(CircularQueue* q); //큐 상태 출력

#endif