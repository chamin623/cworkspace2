#include <stdio.h>
/*
	선택 정렬
	- 배열에서 가장 작은 값을 찾아 맨 앞으로 보내는 방식
	- 현재 행의 첫째 위치 고정
	- 정렬이 안된 영역에서 최소값의 위치를 찾음
	- 앞요소와 교환 처리
*/
int main()
{
	int arr[] = { 41, 36, 8, 77, 15 };
	int i, j, temp;
	int minIdx;

	//비교와 교환 반복
	for (i = 0;i < 4;i++) {
		minIdx = i; //현재 위치(행)을 최소값으로 설정

		for (j = i + 1;j < 5;j++) {
			if (arr[minIdx] > arr[j]) {
				minIdx = j; //비교 후 최소값 위치 변경
			}
		}

		//교환
		temp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = temp;
	}
	/*
		{ 41, 36, 8, 77, 15 }
		1회전(i=0)
		minIdx = 0
		뒤에서 최소값 탐색 - 8(minIdx = 2)
		교환 - { 8, 36, 41, 77, 15 }

		2회전(i=1)
		minIdx=1
		뒤에서 최소값 탐색 - 15(minIdx = 4)
		교환 - { 8, 15, 41, 77, 36 }

		3회전(i=2)
		minIdx=2
		뒤에서 최소값 탐색 - 36(minIdx = 4)
		교환 - { 8, 15, 36, 77, 41 }

		4회전(i=3)
		minIdx=3
		뒤에서 최소값 탐색 - 41(minIdx = 4)
		교환 - { 8, 15, 36, 41, 77 }
	*/
	//출력
	for (i = 0;i < 5;i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}