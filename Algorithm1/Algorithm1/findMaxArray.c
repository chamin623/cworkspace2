//findMaxArray.c
#include <stdio.h>

//최대값 구하는 함수
int findMax(int a[], int len) {
    int max = a[0];

    for (int i = 0; i < len; i++) {
        if (a[i] > max) //max와 arr 요소값을 비교
            max = a[i]; //최대값 변경
    }
    return max;
}

//최대값의 위치 구하는 함수
int findMaxIdx(int a[], int len) {
    int maxIdx = 0; //배열의 첫위치를 최대값으로 지정

    for (int i = 0; i < len; i++) {
        if (a[i] > a[maxIdx])
            maxIdx = i; //인덱스 위치 변경
    }
    return maxIdx;
}

int main()
{
    int arr[] = { 53, 11, 65, 36, 29, 87 };
    int size, max, maxIdx;

    size = sizeof(arr) / sizeof(arr[0]);
    //printf("%d\n", size); // 20/4 = 5

    //최대값 함수 호출
    max = findMax(arr, size);
    printf("최대값: %d\n", max); //65

    //최대값의 위치 함수 호출
    maxIdx = findMaxIdx(arr, size);
    printf("최대값의 위치: %d\n", maxIdx);

    return 0;
}