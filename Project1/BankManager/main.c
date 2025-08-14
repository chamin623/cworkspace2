#include <stdio.h>

static void print_menu(void) {
    printf("\n====== 은행 계좌 관리 ======\n");
    printf("1. 계좌 개설 (Create)\n");
    printf("2. 계좌 조회 (Read)\n");
    printf("3. 입금/출금 (Update)\n");
    printf("4. 계좌 삭제 (Delete)\n");
    printf("0. 종료\n");
    printf("============================\n");
}

int main(void) {
    int choice;
    accounts_init();

    while (1) {
        print_menu();
        printf("메뉴를 선택하세요: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) accounts_create();
        else if (choice == 2) accounts_list();
        else if (choice == 3) accounts_update();
        else if (choice == 4) accounts_delete();
        else if (choice == 0) { printf("프로그램 종료\n"); break; }
        else printf("잘못된 입력입니다.\n");
    }
    return 0;
}