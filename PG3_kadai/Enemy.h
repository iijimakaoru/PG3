#pragma once
#include <stdio.h>
#include <iostream>

class Enemy
{
public:
	void(Enemy::* actionFunc)();

	Enemy(int enemy) 
	{  
		enemyNum = enemy;
		printf("�G%d�����ꂽ\n", enemyNum);
		actionFunc = &Enemy::Melee;
	}
	~Enemy() 
	{ 
		
	}

	void Update()
	{
		if (isAlive)
		{
			(this->*actionFunc)();
		}
	}

	void Death()
	{
		printf("�G%d�͓|�ꂽ�I\n", enemyNum);
		isAlive = false;
	}

	void CorpseKick()
	{
		printf("�G%d�͓|��Ă���\n",enemyNum);
		printf("���̏R��͋S�{�̏��Ƃł���I\n");
	}

	void Melee()
	{
		printf("�G%d�͋ߐڍU�����J��o�����I\n",enemyNum);
		actionFunc = &Enemy::Range;
	}

	void Range()
	{
		printf("�G%d�͉������U�����J��o�����I\n",enemyNum);
		actionFunc = &Enemy::Escape;
	}

	void Escape()
	{
		printf("�G%d�͓������J��o�����I\n", enemyNum);
		actionFunc = &Enemy::Melee;
	}

	bool GetIsAlive()
	{
		return isAlive;
	}

private:
	bool isAlive = true;
	int enemyNum = 0;
};