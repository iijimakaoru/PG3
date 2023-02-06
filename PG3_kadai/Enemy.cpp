#include "Enemy.h"

void (Enemy::* Enemy::actionFunc[])() =
{
	&Enemy::Melee,
	&Enemy::Range,
	&Enemy::Escape
};

Enemy::Enemy(int enemy)
{
	enemyNum = enemy;
	printf("“G%d‚ªŒ»‚ê‚½\n", enemyNum);
}

void Enemy::Update()
{
	if (isAlive)
	{
		(this->*actionFunc[static_cast<size_t>(phase)])();
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
	phase = 1;
}

void Enemy::Range()
{
	printf("“G%d‚Í‰“‹——£UŒ‚‚ğŒJ‚èo‚µ‚½I\n", enemyNum);
	phase = 2;
}

void Enemy::Escape()
{
	printf("“G%d‚Í“¦‘–‚ğŒJ‚èo‚µ‚½I\n", enemyNum);
	phase = 0;
}
