#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <functional>

// �T�C�R��
int GetRand()
{
	srand(time(nullptr));
	int a = rand() % 6 + 1;
	int b = rand() % 6 + 1;

	return a + b;
}
// ����������̔���
int Check(int result)
{
	if (result % 2 == 0)
	{
		return 1;
	}

	return 0;
}
// �o���ڂ̔���
void Result(int result, int input)
{
	printf("%d\n", result);

	if (Check(result) == input)
	{
		printf("����\n");
	}
	else
	{
		printf("�s����\n");
	}

	if (Check(result) == 1)
	{
		printf("�o���ڂ͋���\n");
	}
	else
	{
		printf("�o���ڂ͊\n");
	}
}

int main()
{
	int ans = GetRand();

	int input = -114514;

	printf("�(0)������(1)�����͂��Ă�������\n");
	// ���[�v
	while (input != 0 && input != 1)
	{
		// ����
		scanf_s("%d", &input);

		if (input != 0 && input != 1)
		{
			printf("�(0)������(1)�����͂��Ă�������\n");
		}
	}
	printf("�o���ڂ́E�E�E\n");

	// �W���b�W�����g
	std::function<void()> judge = [=]() {Result(ans, input); };

	// ���������Ԃ�֐�
	std::function<void(std::function<void()>, int)> setTimeOut = [](std::function<void()> judge, int time) { Sleep(time * 1000), judge(); };
	
	// 3�b�҂�
	setTimeOut(judge, 3);

	return 0;
}