#include <iostream>
#include <vector>
#include <list>

#include "Enemy.h"

using namespace std;

int Enemy::enemyCount;

int main()
{
	Enemy* enemy1 = new Enemy;
	Enemy* enemy2 = new Enemy;
	Enemy* enemy3 = new Enemy;

	int input = 0;
	printf("どれを攻撃する？\n");
	while (input < 1 || input > 3)
	{
		scanf_s("%d", &input);
	}
	printf("敵%dへ攻撃！\n",input);

	printf("敵%dは爆発した！\n", input);
	printf("爆発はすべての敵を巻き込んだ！\n");
	delete enemy1;
	delete enemy2;
	delete enemy3;

	return 0;
}