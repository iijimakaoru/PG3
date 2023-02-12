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

	// �o�^����Ă���^�X�N��
	void AllTask();

	// �^�X�N����
	void CreateTask();

	// ���ؓ��ύX
	void ChangeDeadLine();

	// ��ԕύX
	void ChangeState();

	// �^�X�N�폜
	void DeleteTaskSelect();

	void SetState(unsigned int taskId, bool _state);
	void SetDeadLine(unsigned int id, Date _deadline);

private:
	std::list<std::unique_ptr<Task>> tasks;
	PICManager* picMan = PICManager::GetInstance();
};

