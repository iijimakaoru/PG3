#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
#include "PIC.h"

struct Date
{
	unsigned short int day;
	unsigned short int month;
};

class Task
{
private:
	// ID
	unsigned int id;
	// �S����
	PIC* pic;
	// �薼
	std::string name;
	// ���e
	std::string content;
	// �D��x
	std::string priority;
	// ����
	Date deadline;
	// ���
	bool state;
public:
	Task(unsigned int id,PIC* _pic, Date _deadline, bool _state, std::string _name = "�ق�", std::string _content = "���������ɂ��肢", std::string _priority = "��");
	// ID�擾
	int GetID();
	// �薼�擾
	std::string GetName();
	// ���e�擾
	std::string GetContent();
	// �D��x�擾
	std::string GetPriority();
	// �����擾
	Date GetDeadLine();
	// ��Ԏ擾
	bool GetState();
	// ��ԃZ�b�g
	void SetState(bool _state);
	// ���e�Z�b�g
	void SetContent(std::string _content);
	// �D��x�Z�b�g
	void SetPriority(std::string _priority);
	// �����Z�b�g
	void SetDeadLine(Date _deadLine);
};

