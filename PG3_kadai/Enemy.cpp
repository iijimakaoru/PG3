#include "Enemy.h"

Enemy::Enemy(int enemy)
{
	enemyNum = enemy;
	printf("敵%dが現れた\n", enemyNum);
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
	printf("敵%dは爆発した！\n", enemyNum);
	printf("敵%dは倒れた！\n", enemyNum);
	isAlive = false;
}

void Enemy::CorpseKick()
{
	printf("敵%dは倒れている\n", enemyNum);
}

void Enemy::Melee()
{
	printf("敵%dは近接攻撃を繰り出した！\n", enemyNum);
	actionFunc = &Enemy::Range;
}

void Enemy::Range()
{
	printf("敵%dは遠距離攻撃を繰り出した！\n", enemyNum);
	actionFunc = &Enemy::Escape;
}

void Enemy::Escape()
{
	printf("敵%dは逃走を繰り出した！\n", enemyNum);
	actionFunc = &Enemy::Melee;
}
