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
	printf("�ǂ���U������H\n");
	while (input < 1 || input > 3)
	{
		scanf_s("%d", &input);
	}
	printf("�G%d�֍U���I\n",input);

	printf("�G%d�͔��������I\n", input);
	printf("�����͂��ׂĂ̓G���������񂾁I\n");
	delete enemy1;
	delete enemy2;
	delete enemy3;

	return 0;
}