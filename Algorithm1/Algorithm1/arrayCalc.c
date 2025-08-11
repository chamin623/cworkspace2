#include <stdio.h>
//배열을 이용한 평균 계산
int main()
{
    int a[] = { 70, 80, 65, 90 };
    int i, sum = 0;

    //단순 평균
    printf("평균: %.1f\n", (a[0] + a[1] + a[2] + a[3]) / 4.0);

    //반복문 사용
    for (i = 0; i < 4; i++) {
        sum += a[i];
    }

    printf("평균: %.1lf\n", sum / 4.0);

    return 0;
}