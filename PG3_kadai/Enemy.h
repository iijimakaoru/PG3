#pragma once
#include <stdio.h>
#include <iostream>

class Enemy
{
public:
	// s“®ƒe[ƒuƒ‹
	static void(Enemy::* actionFunc[])();

	// “oê•¶(‰Šú‰»)
	Enemy(int enemy);
	~Enemy() {}

	// s“®
	void Update();

	// €–S•¶
	void Death();

	// €‚ñ‚Å‚é“G‚ğUŒ‚‚µ‚½‚Æ‚«
	void CorpseKick();

	// ‹ßÚUŒ‚
	void Melee();

	// ‰“‹——£UŒ‚
	void Range();

	// “¦‚°‚é
	void Escape();

	// ¶‘¶ƒtƒ‰ƒO
	bool GetIsAlive() { return isAlive; }

private:
	bool isAlive = true;
	int enemyNum = 0;

	int phase = 0;
};