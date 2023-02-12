#include "Task.h"

Task::Task(unsigned int id, PIC* _pic, Date _deadline, bool _state, std::string _name, std::string _content, std::string _priority)
{
	pic = _pic;
	name = _name;
	content = _content;
	priority = _priority;
	deadline = _deadline;
	state = _state;
}

int Task::GetID() { return id; }

std::string Task::GetName() { return name; }

std::string Task::GetContent() { return content; }

std::string Task::GetPriority() { return priority; }

Date Task::GetDeadLine() { return deadline; }

bool Task::GetState() { return state; }

void Task::SetState(bool _state) { state = _state; }

void Task::SetContent(std::string _content) { content = _content; }

void Task::SetPriority(std::string _priority) { priority = _priority; }

void Task::SetDeadLine(Date _deadLine) { deadline = _deadLine; }
