#define _CRT_SECURE_NO_WARNINGS
#define MAX 100 
#include "account.h"

static Account accounts[MAX];
static int count = 0;

void account_init(void) {
	count = 0;
}

void accounts_create(void) {
    if (count >= MAX) {
        printf("더 이상 계좌를 생성할 수 없습니다.\n");
        return;
    }
    printf("\n[계좌 개설]\n");
    printf("ID: ");
    scanf("%d", &accounts[count].id);
    printf("이름(공백X): ");

    accounts[count].name = malloc(20);
    scanf("%49s", accounts[count].name);
    printf("초기 입금액: ");
    scanf("%d", &accounts[count].balance);
    count++;
    printf("계좌가 생성되었습니다.\n");
}

void account_update(void) {

}

void account_delete(void) {
    int id, idx = -1;
    printf("\n[계좌 삭제]\nID 입력 : ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (accounts[i].id == id) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("해당 ID의 계좌를 찾을 수 없습니다.\n");
        return;
    }

    for (int j = idx; j < count - 1; j++) {
        accounts[j] = accounts[j + 1];
    }

    count--;
    printf("계좌가 삭제되었습니다.\n ")
}

void account_list(void) {

}

void accounts_list(void) {
    printf("\n[계좌 목록]\n");
    if (count == 0) {
        printf("등록된 계좌가 없습니다.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("ID: %d | 이름: %s | 잔액: %d\n",
            accounts[i].id, accounts[i].name, accounts[i].balance);
    }
}