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
	CELL* prev = nullptr;
	CELL* next = nullptr;
};

void Create(CELL* head, const char* buf)
{
	CELL* cell;
	// 
	cell = (CELL*)malloc(sizeof(CELL));
	strcpy_s(cell->str, 8, buf);

	//cell->val = val;
	cell->prev = head;
	cell->next = nullptr;

	// 
	// 
	while (head->next != nullptr)
	{
		head = head->next;
	}

	head->next = cell;
}

void Index(CELL* head)
{
	while (head->next != nullptr)
	{
		head = head->next;
		printf("�u%s�v\n", head->str);
	}
}

void Delete(CELL* head)
{
	CELL* newCell = head;

	if (newCell->next == nullptr)
	{
		delete newCell;
	}

	while (newCell->next != nullptr)
	{
		if (newCell->next->next == nullptr)
		{
			delete newCell->next;
			newCell->next = nullptr;
			break;
		}
		newCell = newCell->next;
	}
}

int main()
{
	int num = 0;

	int yousoNum = 0;

	char str[8];
	CELL head;
	head.next = nullptr;

	while (true)
	{
		printf("[�v�f�̑���]\n");
		printf("1.�Ō���ɒǉ�\n");
		printf("2.�ꗗ\n");
		printf("3.�Ō���̍폜\n");
		printf("----------------\n");
		printf("\n");

		scanf_s("%d", &num);

		if (num == 1)
		{
			printf("�ǉ�����l����͂��Ă�������\n");
			scanf_s("%s", str, 8);
			Create(&head, str);
			yousoNum++;
			printf("�u%s�v���ǉ�����܂���\n", str);
			printf("----------------\n");
			printf("\n");
		}
		else if (num == 2)
		{
			printf("���݂̗v�f�ꗗ\n");
			Index(&head);
			printf("�v�f���F%d\n", yousoNum);
			printf("----------------\n");
			printf("\n");
		}
		else if (num == 3)
		{
			printf("�Ō���̗v�f���폜���܂���\n");
			printf("----------------\n");
			printf("\n");
			Delete(&head);
			if (yousoNum > 0)
			{
				yousoNum--;
			}
		}
	}

	return 0;
}