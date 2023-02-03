#pragma once
#include <stdio.h>

class Enemy
{
protected:
public:
	static int enemyCount;
	Enemy() 
	{ 
		enemyCount++; 
		printf("“G%d‚ªŒ»‚ê‚½\n", enemyCount);
	}
	~Enemy() 
	{ 
		enemyCount--; 
		printf("“G%d‚Í“|‚ê‚½\n", 3 - enemyCount);
	}
};

