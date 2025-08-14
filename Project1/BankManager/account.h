#pragma once
#define MAX 100

typedef struct ACCOUNT {
	int id;
	char* name[20];
	int balance;
}Account;

void account_init(void);
void account_create(void);
void account_update(void);
void account_delete(void);
void account_list(void);