#include "Enemy.h"

Enemy::Enemy(int enemy)
{
	enemyNum = enemy;
	printf("“G%d‚ªŒ»‚ê‚½\n", enemyNum);
	actionFunc = &Enemy::Melee;
}

void Enemy::Update()
{
	if (isAlive)
	{
		(this->*actionFunc)();
	}
}

void Enemy::Death()
{
	printf("“G%d‚Í”š”­‚µ‚½I\n", enemyNum);
	printf("“G%d‚Í“|‚ê‚½I\n", enemyNum);
	isAlive = false;
}

void Enemy::CorpseKick()
{
	printf("“G%d‚Í“|‚ê‚Ä‚¢‚é\n", enemyNum);
}

void Enemy::Melee()
{
	printf("“G%d‚Í‹ßÚUŒ‚‚ğŒJ‚èo‚µ‚½I\n", enemyNum);
	actionFunc = &Enemy::Range;
}

void Enemy::Range()
{
	printf("“G%d‚Í‰“‹——£UŒ‚‚ğŒJ‚èo‚µ‚½I\n", enemyNum);
	actionFunc = &Enemy::Escape;
}

void Enemy::Escape()
{
	printf("“G%d‚Í“¦‘–‚ğŒJ‚èo‚µ‚½I\n", enemyNum);
	actionFunc = &Enemy::Melee;
}
