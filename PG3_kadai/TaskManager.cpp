#include "TaskManager.h"

using namespace std;

TaskManager* TaskManager::GetInstance()
{
	static TaskManager instance;
	return &instance;
}

void TaskManager::AllTask()
{
    cout << "���ݓo�^����Ă���^�X�N 1:���� 0:������" << endl;
    for (auto& itr : tasks)
    {
        cout << "�^�X�NID:" << itr->GetID() <<
            " �^�X�N��:" << itr->GetName() <<
            " �^�X�N���e:" << itr->GetContent() <<
            " �^�X�N�D��x:" << itr->GetPriority() <<
            " �^�X�N����:" << itr->GetDeadLine().month << "/" << itr->GetDeadLine().day <<
            " �^�X�N���:" << itr->GetState() << "\n" << endl;
    }
}

void TaskManager::CreateTask()
{
	string name;
	string content;
	string priority;
	Date deadline;
	bool state;
	int picId;
	// �薼
	cout << "�薼�����" << endl;
	cin >> name;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	// ���e
	cout << "���e�����" << endl;
	cin >> content;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	// �D��x
	cout << "�D��x�����" << endl;
	cin >> priority;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	/// ����
	// ��
	cout << "����(��)�����" << endl;
	cin >> deadline.month;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	// ��
	cout << "����(��)�����" << endl;
	cin >> deadline.day;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	// ���
	cout << "��Ԃ����" << endl;
	cout << "1:����,0:������" << endl;
	cin >> state;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	// ID
	cout << "�S���҂�ID�����" << endl;
	cin >> picId;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	int addId = AddTask(picId, name, content, priority, deadline, state);
	cout << "ID�F" << addId << "�^�X�N���F" << name << "��ǉ�" << endl;
}

void TaskManager::ChangeDeadLine()
{
	int id = -1;
	Date deadline;
	// ID����
	cout << "ID�����" << endl;
	AllTask();
	cin >> id;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	// ����(��)
	cout << "����(��)�����" << endl;
	cin >> deadline.month;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	// ����(��)
	cout << "����(��)�����" << endl;
	cin >> deadline.day;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	SetDeadLine(id, deadline);
	cout << "ID�F" << id << "�̊�����" << " " << deadline.month << "/" << " " << deadline.day << "�ɕύX" << endl;
}

void TaskManager::ChangeState()
{
	int id = -1;
	bool state;
	// ID����
	cout << "ID�����" << endl;
	AllTask();
	cin >> id;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	// ���
	cout << "��Ԃ���� 1:����,0: ������" << endl;
	cin >> state;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	SetState(id, state);
	cout << "ID�F" << id << "�̏�Ԃ�" << " " << state << "�ɕύX" << endl;
}

void TaskManager::DeleteTaskSelect()
{
	int id = -1;
	// ID����
	cout << "ID�����" << endl;
	AllTask();
	cin >> id;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	DeleteTask(id);
	cout << "----" << endl;
}

unsigned int TaskManager::AddTask(unsigned int picId, std::string _name, std::string _content, std::string _priority, Date deadline, bool _state)
{
    int id = 1;
    for (unsigned int i = 0; i < tasks.size(); i++)
    {
        bool success = true;
        id++;
        for (auto& itr : tasks)
        {
            if (itr->GetID() == id)
            {
                success = false;
                break;
            }
        }
        if (success)
        {
            unique_ptr<Task> newTask = make_unique<Task>(id, picMan->GetPic(picId), deadline, _state, _name, _content, _priority);
            tasks.push_back(move(newTask));
            return id;
        }

    }
    if (tasks.size() == 0)
    {
        int id = 1;
        unique_ptr<Task> temp = make_unique<Task>(id, picMan->GetPic(picId), deadline, _state, _name, _content, _priority);
        tasks.push_back(move(temp));
        return id;
    }
    return -1;
}

void TaskManager::DeleteTask(unsigned int taskId)
{
    tasks.remove_if([=](auto& itr) {return itr->GetID() == taskId; });
    cout << "ID:" << " " << taskId << "���폜" << endl;
}

void TaskManager::SetState(unsigned int taskId, bool _state)
{
    for (auto& itr : tasks)
    {
        if (itr->GetID() == taskId)
        {
            itr->SetState(_state);
            return;
        }
    }
}

void TaskManager::SetDeadLine(unsigned int id, Date _deadline)
{
    for (auto& itr : tasks)
    {
        if (itr->GetID() == id)
        {
            itr->SetDeadLine(_deadline);
            return;
        }
    }
}
