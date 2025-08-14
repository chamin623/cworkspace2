#include <stdio.h>
#include <stdlib.h>
/*
	순위 정하기
	- 배열의 한 요소가 모든 요소와 비교함
	- rank 배열을 1로 초기화
	- 어떤 요소가 자기보다 크면 rank 요소를 1 증가시킴
*/

void calcRank(int a[], int rank[], int n) {
	int i, j;

	//비교 후 순위 결정
	for (i = 0;i < n;i++) {
		rank[i] = 1; //초기 순위
		for (j = 0;j < n;j++) {
			if (a[i] < a[j])
				rank[i] += 1;
		}
	}
}

int main()
{
	int arr[] = { 41, 8, 36, 77, 15, 60 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//int rank[5];
	int* rank; //동적 할당
	int i;

	rank = (int*)malloc(sizeof(int) * size);

	calcRank(arr, rank, size); //순위 함수 호출

	//순위 출력
	for (i = 0;i < size;i++) {
		printf("%d ", rank[i]);
	}

	free(rank);

	return 0;
}