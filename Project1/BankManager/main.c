#include <stdio.h>

static void print_menu(void) {
    printf("\n====== ���� ���� ���� ======\n");
    printf("1. ���� ���� (Create)\n");
    printf("2. ���� ��ȸ (Read)\n");
    printf("3. �Ա�/��� (Update)\n");
    printf("4. ���� ���� (Delete)\n");
    printf("0. ����\n");
    printf("============================\n");
}

int main(void) {
    int choice;
    accounts_init();

    while (1) {
        print_menu();
        printf("�޴��� �����ϼ���: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) accounts_create();
        else if (choice == 2) accounts_list();
        else if (choice == 3) accounts_update();
        else if (choice == 4) accounts_delete();
        else if (choice == 0) { printf("���α׷� ����\n"); break; }
        else printf("�߸��� �Է��Դϴ�.\n");
    }
    return 0;
}