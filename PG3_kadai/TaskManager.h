#pragma once
#include "Task.h"
#include "PICManager.h"
#include <list>
#include <memory>

class TaskManager
{
private:
	TaskManager(){};
	~TaskManager(){};
	unsigned int AddTask(unsigned int picId, std::string _name, std::string _content, std::string _priority, Date deadline, bool _state);
	void DeleteTask(unsigned int taskId);

public:
	TaskManager(const TaskManager& m) = delete;
	TaskManager& operator=(const TaskManager& manager) = delete;
	static TaskManager* GetInstance();

	// 登録されているタスク列挙
	void AllTask();

	// タスク生成
	void CreateTask();

	// 締切日変更
	void ChangeDeadLine();

	// 状態変更
	void ChangeState();

	// タスク削除
	void DeleteTaskSelect();

	void SetState(unsigned int taskId, bool _state);
	void SetDeadLine(unsigned int id, Date _deadline);

private:
	std::list<std::unique_ptr<Task>> tasks;
	PICManager* picMan = PICManager::GetInstance();
};

