#include <stdio.h>
/*
	버블 정렬(Bubble Sorting)
	- 배열에서 인접한 두 개의 요소를 비교하여 자리를 바꾸는 방식
	- 요소의 개수가 n개인 배열에서 n-1회 비교하고 교환함
*/
int main()
{
	int arr[] = { 41, 8, 36, 77, 15 };
	int i, j, temp;

	//비교와 교환 반복
	for (i = 0;i < 5;i++) { //전체 비교를 5번
		for (j = 0;j < 4;j++) { //열의 요소 비교
			if (arr[j] > arr[j + 1]) { //앞 요소가 뒤 요소보다 크면 자리 바꿈 - 오름차순 정렬
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	//출력
	for (i = 0;i < 5;i++)
		printf("%d ", arr[i]);

	return 0;
}