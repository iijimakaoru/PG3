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
		printf("敵%dが現れた\n", enemyNum);
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
		printf("敵%dは爆発した！\n", enemyNum);
		printf("敵%dは倒れた！\n", enemyNum);
		isAlive = false;
	}

	void CorpseKick()
	{
		printf("敵%dは倒れている\n",enemyNum);
		printf("死体蹴りは鬼畜の所業である！\n");
	}

	void Melee()
	{
		printf("敵%dは近接攻撃を繰り出した！\n",enemyNum);
		actionFunc = &Enemy::Range;
	}

	void Range()
	{
		printf("敵%dは遠距離攻撃を繰り出した！\n",enemyNum);
		actionFunc = &Enemy::Escape;
	}

	void Escape()
	{
		printf("敵%dは逃走を繰り出した！\n", enemyNum);
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