#include <iostream>
#include <vector>
#include <list>
#include <string>

#include "Enemy.h"

using namespace std;

int main()
{
	// 敵出現
	Enemy enemy1 = Enemy(1);
	Enemy enemy2 = Enemy(2);
	Enemy enemy3 = Enemy(3);

	while (true)
	{
		// 敵の行動
		enemy1.Update();
		enemy2.Update();
		enemy3.Update();

		int input = -1;

		// クリア条件
		if (!enemy1.GetIsAlive() && !enemy2.GetIsAlive() && !enemy3.GetIsAlive())
		{
			printf("あなたは勝利した！\n");
			break;
		}

		// プレイヤー入力
		printf("どれを攻撃する？\n");
		scanf_s("%d", &input);
		printf("敵%dへ攻撃！\n", input);
		
		// 入力結果
		switch (input)
		{
		case 1:
			if (enemy1.GetIsAlive())
			{
				enemy1.Death();
			}
			else
			{
				enemy1.CorpseKick();
			}
			break;
		case 2:
			if (enemy2.GetIsAlive())
			{
				enemy2.Death();
			}
			else
			{
				enemy2.CorpseKick();
			}
			break;
		case 3:
			if (enemy3.GetIsAlive())
			{
				enemy3.Death();
			}
			else
			{
				enemy3.CorpseKick();
			}
			break;
		default:
			printf("そんな敵は存在しない！\n");
			break;
		}
	}

	return 0;
}