#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <functional>

// サイコロ
int GetRand()
{
	srand(time(nullptr));
	int a = rand() % 6 + 1;
	int b = rand() % 6 + 1;

	return a + b;
}
// 奇数か偶数かの判定
int Check(int result)
{
	if (result % 2 == 0)
	{
		return 1;
	}

	return 0;
}
// 出た目の判定
void Result(int result, int input)
{
	printf("%d\n", result);

	if (Check(result) == input)
	{
		printf("正解\n");
	}
	else
	{
		printf("不正解\n");
	}

	if (Check(result) == 1)
	{
		printf("出た目は偶数\n");
	}
	else
	{
		printf("出た目は奇数\n");
	}
}

int main()
{
	int ans = GetRand();

	int input = -114514;

	printf("奇数(0)か偶数(1)か入力してください\n");
	// ループ
	while (input != 0 && input != 1)
	{
		// 入力
		scanf_s("%d", &input);

		if (input != 0 && input != 1)
		{
			printf("奇数(0)か偶数(1)か入力してください\n");
		}
	}
	printf("出た目は・・・\n");

	// ジャッジメント
	std::function<void()> judge = [=]() {Result(ans, input); };

	// もったいぶる関数
	std::function<void(std::function<void()>, int)> setTimeOut = [](std::function<void()> judge, int time) { Sleep(time * 1000), judge(); };
	
	// 3秒待つ
	setTimeOut(judge, 3);

	return 0;
}