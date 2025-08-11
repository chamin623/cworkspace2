//sumN.c
#include <stdio.h>
/*
   - 시간 복잡도(빅 오 - Big O)
   1부터 n까지의 합계
   방법 1: n번 덧셈 - O(n)
   방법 2: 덧셈1, 곱셈1, 나눗셈1 - O(1)
*/

//덧셈 알고리즘1
int sumN(int n) {
    int i, sum = 0;

    for (i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

//덧셈 알고리즘2
int sumN2(int n) {
    int sum = 0;//sumN.c
#include <stdio.h>
    /*
       - 시간 복잡도(빅 오 - Big O)
       1부터 n까지의 합계
       방법 1: n번 덧셈 - O(n)
       방법 2: 덧셈1, 곱셈1, 나눗셈1 - O(1)
    */

    //덧셈 알고리즘1
    int sumN(int n) {
        int i, sum = 0;

        for (i = 1; i <= n; i++) {
            sum += i;
        }
        return sum;
    }

    //덧셈 알고리즘2
    int sumN2(int n) {
        int sum = 0;
        sum = (n * (n + 1)) / 2;
        return sum;
    }


    int main()
    {
        int value1, value2;

        //sumN() 호출
        value1 = sumN(10);

        //sumN2() 호출
        value2 = sumN2(10);

        printf("합계1: %d\n", value1); //55
        printf("합계2: %d\n", value2); //55

        return 0;
    }
    sum = (n * (n + 1)) / 2;
    return sum;
}


int main()
{
    int value1, value2;

    //sumN() 호출
    value1 = sumN(10);

    //sumN2() 호출
    value2 = sumN2(10);

    printf("합계1: %d\n", value1); //55
    printf("합계2: %d\n", value2); //55

    return 0;
}