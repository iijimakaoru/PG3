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
	// 担当者
	PIC* pic;
	// 題名
	std::string name;
	// 内容
	std::string content;
	// 優先度
	std::string priority;
	// 期限
	Date deadline;
	// 状態
	bool state;
public:
	Task(unsigned int id,PIC* _pic, Date _deadline, bool _state, std::string _name = "ほげ", std::string _content = "いい感じにお願い", std::string _priority = "高");
	// ID取得
	int GetID();
	// 題名取得
	std::string GetName();
	// 内容取得
	std::string GetContent();
	// 優先度取得
	std::string GetPriority();
	// 期限取得
	Date GetDeadLine();
	// 状態取得
	bool GetState();
	// 状態セット
	void SetState(bool _state);
	// 内容セット
	void SetContent(std::string _content);
	// 優先度セット
	void SetPriority(std::string _priority);
	// 期限セット
	void SetDeadLine(Date _deadLine);
};

