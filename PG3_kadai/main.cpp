#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <functional>
#include <list>
#include <string>

typedef struct CELL
{
	char str[8];
	struct CELL* next;
};

void Create(CELL* farst, const char* buf)
{
	CELL* cell;
	// 
	cell = (CELL*)malloc(sizeof(CELL));
	strcpy_s(cell->str, 8, buf);

	//cell->val = val;
	cell->next = nullptr;

	// 
	// 
	while (farst->next != nullptr)
	{
		farst = farst->next;
	}

	farst->next = cell;
}

void Index(CELL* farst)
{
	while (farst->next != nullptr)
	{
		farst = farst->next;
		printf("%s\n", farst->str);
	}
}

int main()
{
	char str[8];
	CELL head;
	head.next = nullptr;

	while (true)
	{
		scanf_s("%s", str, 8);

		Create(&head, str);

		Index(&head);
	}

	return 0;
}