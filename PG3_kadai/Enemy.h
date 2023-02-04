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
		printf("“G%d‚ªŒ»‚ê‚½\n", enemyNum);
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
		printf("“G%d‚Í“|‚ê‚½I\n", enemyNum);
		isAlive = false;
	}

	void CorpseKick()
	{
		printf("“G%d‚Í“|‚ê‚Ä‚¢‚é\n",enemyNum);
		printf("€‘ÌR‚è‚Í‹S’{‚ÌŠ‹Æ‚Å‚ ‚éI\n");
	}

	void Melee()
	{
		printf("“G%d‚Í‹ßÚUŒ‚‚ğŒJ‚èo‚µ‚½I\n",enemyNum);
		actionFunc = &Enemy::Range;
	}

	void Range()
	{
		printf("“G%d‚Í‰“‹——£UŒ‚‚ğŒJ‚èo‚µ‚½I\n",enemyNum);
		actionFunc = &Enemy::Escape;
	}

	void Escape()
	{
		printf("“G%d‚Í“¦‘–‚ğŒJ‚èo‚µ‚½I\n", enemyNum);
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