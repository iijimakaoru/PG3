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
	std::function<void()> judge = [=]() 
	{
		printf("%d\n", ans), // �o���ڂ̕\��
		Check(ans) == 1 ? printf("����\n") : printf("�\n"), // ����������\��
		Check(ans) == input ? printf("����\n") : printf("�s����\n"); // �������s�������\��
	};

	// ���������Ԃ�֐�
	std::function<void(std::function<void()>, int)> setTimeOut = [](std::function<void()> judge, int time) 
	{ 
		printf("%d�b��ɓ���\n",time), // �b���\��
			Sleep(time * 1000), // time�b�҂�
			judge(); // judge�֐�
	};
	
	setTimeOut(judge, 3);

	return 0;
}