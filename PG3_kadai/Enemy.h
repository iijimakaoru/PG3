#pragma once
#include <stdio.h>
#include <iostream>

class Enemy
{
public:
	// 行動テーブル
	static void(Enemy::* actionFunc[])();

	// 登場文(初期化)
	Enemy(int enemy);
	~Enemy() {}

	// 行動
	void Update();

	// 死亡文
	void Death();

	// 死んでる敵を攻撃したとき
	void CorpseKick();

	// 近接攻撃
	void Melee();

	// 遠距離攻撃
	void Range();

	// 逃げる
	void Escape();

	// 生存フラグ
	bool GetIsAlive() { return isAlive; }

private:
	bool isAlive = true;
	int enemyNum = 0;

	int phase = 0;
};