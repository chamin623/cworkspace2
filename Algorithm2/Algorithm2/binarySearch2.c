#include <stdio.h>

int binarySearch(int a[], int n, int x) {
	int low, high, mid;

	low = 0;	//첫 인덱스
	high = 8;	//마지막 인덱스

	while (low <= high) {
		//중간 인덱스
		mid = (low + high) / 2;
		//printf("%d\n", mid);

		if (a[mid] == x) {
			return mid; //찾은 위치 반환
		}

		else if (a[mid] < x) {
			low = mid + 1;
		}

		else {
			high = mid - 1;
		}
	}
	//찾지 못함
	return -1;
}

/*
	low=0, high=8
	mid=4, 5<8, 인덱스 -> low=5, high=8, mid=6
	mid=6, 7<8, 인덱스 -> low=7, high=8, mid=7
	mid=7, 8=8, 찾음
*/

int main()
{
	//정렬된 배열
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int x = 7; //찾을 값
	int size = sizeof(arr) / sizeof(arr[0]);
	int idx; //찾은 위치

	idx = binarySearch(arr, size, x);
	if (idx==-1)
		printf("%d는(은) 없습니다.\n", x);
	else {
		printf("%d는(은) a[%d]에 있습니다.\n", x, idx);
	}

	return 0;
}