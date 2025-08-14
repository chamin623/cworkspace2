#include <stdio.h>

int main()
{
	//정렬된 배열
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int low, high, mid;
	int x; //찾을 값
	int found; //상태(토굴) (찾음/못찾음)

	low = 0;	//첫 인덱스
	high = 8;	//마지막 인덱스
	x = 10;
	found = 0;

	while (low<=high) {
		//중간 인덱스
		mid = (low + high) / 2;
		//printf("%d\n", mid);
		
		if (arr[mid] == x) {
			printf("%d는(은) a[%d]에 있습니다.\n", x, mid);
			found = 1;
			break;
		}

		else if (arr[mid] < x) {
			low = mid + 1;
		}

		else {
			high = mid - 1;
		}
	}
	/*
		low=0, high=8
		mid=4, 5<8, 인덱스 -> low=5, high=8, mid=6
		mid=6, 7<8, 인덱스 -> low=7, high=8, mid=7
		mid=7, 8=8, 찾음
	*/
	if (!found)
		printf("%d는(은) 없습니다.\n", x);

	return 0;
}