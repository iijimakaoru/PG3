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
		printf("�G%d�����ꂽ\n", enemyCount);
	}
	~Enemy() 
	{ 
		enemyCount--; 
		printf("�G%d�͓|�ꂽ\n", 3 - enemyCount);
	}
};

