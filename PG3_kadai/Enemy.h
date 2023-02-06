#pragma once
#include <stdio.h>
#include <iostream>

class Enemy
{
public:
	// �s���e�[�u��
	static void(Enemy::* actionFunc[])();

	// �o�ꕶ(������)
	Enemy(int enemy);
	~Enemy() {}

	// �s��
	void Update();

	// ���S��
	void Death();

	// ����ł�G���U�������Ƃ�
	void CorpseKick();

	// �ߐڍU��
	void Melee();

	// �������U��
	void Range();

	// ������
	void Escape();

	// �����t���O
	bool GetIsAlive() { return isAlive; }

private:
	bool isAlive = true;
	int enemyNum = 0;

	int phase = 0;
};