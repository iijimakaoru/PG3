#include "Enemy.h"

Enemy::Enemy(int enemy)
{
	enemyNum = enemy;
	printf("�G%d�����ꂽ\n", enemyNum);
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
	printf("�G%d�͔��������I\n", enemyNum);
	printf("�G%d�͓|�ꂽ�I\n", enemyNum);
	isAlive = false;
}

void Enemy::CorpseKick()
{
	printf("�G%d�͓|��Ă���\n", enemyNum);
}

void Enemy::Melee()
{
	printf("�G%d�͋ߐڍU�����J��o�����I\n", enemyNum);
	actionFunc = &Enemy::Range;
}

void Enemy::Range()
{
	printf("�G%d�͉������U�����J��o�����I\n", enemyNum);
	actionFunc = &Enemy::Escape;
}

void Enemy::Escape()
{
	printf("�G%d�͓������J��o�����I\n", enemyNum);
	actionFunc = &Enemy::Melee;
}
