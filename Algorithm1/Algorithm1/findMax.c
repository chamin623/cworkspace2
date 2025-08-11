//findMax.c
#include <stdio.h>

int max3(int a, int b, int c) {
    int max = a; //최대값 지정

    if (b > max)
        max = b;
    if (c > max)
        max = c;

    return max; //최대값 결과 반환
}

int main()
{
    //두 수 중에서 큰 값 계산
    int x = 10, y = 20;
    int result; //더 큰 값 저장

    result = (x > y) ? x : y;
    printf("두 수 중 더 큰 수: %d\n", result); //20

    //세 개의 수 중에서 최대값 찾기

    printf("max3(%d, %d, %d) = %d\n", 20, 10, 30, max3(20, 10, 30));
    printf("max3(%d, %d, %d) = %d\n", 20, 30, 10, max3(20, 30, 10));

    /*int a = 10, b = 20, c = 30;
    int max;

    //첫째수를 최대값으로 지정
    max = a;
    if (b > max) {
       max = b;
    }
    if (c > max) {
       max = c;
    }

    printf("최대값은 %d입니다.\n", max);*/

    return 0;
}