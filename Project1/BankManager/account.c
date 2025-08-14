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
        printf("�� �̻� ���¸� ������ �� �����ϴ�.\n");
        return;
    }
    printf("\n[���� ����]\n");
    printf("ID: ");
    scanf("%d", &accounts[count].id);
    printf("�̸�(����X): ");

    accounts[count].name = malloc(20);
    scanf("%49s", accounts[count].name);
    printf("�ʱ� �Աݾ�: ");
    scanf("%d", &accounts[count].balance);
    count++;
    printf("���°� �����Ǿ����ϴ�.\n");
}

void account_update(void) {

}

void account_delete(void) {
    int id, idx = -1;
    printf("\n[���� ����]\nID �Է� : ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (accounts[i].id == id) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("�ش� ID�� ���¸� ã�� �� �����ϴ�.\n");
        return;
    }

    for (int j = idx; j < count - 1; j++) {
        accounts[j] = accounts[j + 1];
    }

    count--;
    printf("���°� �����Ǿ����ϴ�.\n ")
}

void account_list(void) {

}

void accounts_list(void) {
    printf("\n[���� ���]\n");
    if (count == 0) {
        printf("��ϵ� ���°� �����ϴ�.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("ID: %d | �̸�: %s | �ܾ�: %d\n",
            accounts[i].id, accounts[i].name, accounts[i].balance);
    }
}