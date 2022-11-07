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
	std::function<void()> judge = [=]() 
	{
		printf("%d\n", ans), // 出た目の表示
		Check(ans) == 1 ? printf("偶数\n") : printf("奇数\n"), // 偶数か奇数か表示
		Check(ans) == input ? printf("正解\n") : printf("不正解\n"); // 正解か不正解か表示
	};

	// もったいぶる関数
	std::function<void(std::function<void()>, int)> setTimeOut = [](std::function<void()> judge, int time) 
	{ 
		printf("%d秒後に答え\n",time), // 秒数表示
			Sleep(time * 1000), // time秒待つ
			judge(); // judge関数
	};
	
	setTimeOut(judge, 3);

	return 0;
}