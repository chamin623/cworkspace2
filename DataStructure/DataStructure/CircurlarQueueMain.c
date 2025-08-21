//CircularQueueMain.c - 
#include <stdio.h>
#include <stdbool.h>
#include "CircularQueue.h"

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
	printQueue(&q1);

	puts("=== 큐2에 데이터 넣기 ===");
	enQueue(&q2, 100);
	enQueue(&q2, 200);
	printQueue(&q2);

	return 0;
}