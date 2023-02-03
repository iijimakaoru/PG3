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
	printf("‚Ç‚ê‚ğUŒ‚‚·‚éH\n");
	while (input < 1 || input > 3)
	{
		scanf_s("%d", &input);
	}
	printf("“G%d‚ÖUŒ‚I\n",input);

	printf("“G%d‚Í”š”­‚µ‚½I\n", input);
	printf("”š”­‚Í‚·‚×‚Ä‚Ì“G‚ğŠª‚«‚ñ‚¾I\n");
	delete enemy1;
	delete enemy2;
	delete enemy3;

	return 0;
}