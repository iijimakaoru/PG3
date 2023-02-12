#include "TaskManager.h"

using namespace std;

TaskManager* TaskManager::GetInstance()
{
	static TaskManager instance;
	return &instance;
}

void TaskManager::AllTask()
{
    cout << "現在登録されているタスク 1:完了 0:未完了" << endl;
    for (auto& itr : tasks)
    {
        cout << "タスクID:" << itr->GetID() <<
            " タスク名:" << itr->GetName() <<
            " タスク内容:" << itr->GetContent() <<
            " タスク優先度:" << itr->GetPriority() <<
            " タスク期限:" << itr->GetDeadLine().month << "/" << itr->GetDeadLine().day <<
            " タスク状態:" << itr->GetState() << "\n" << endl;
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
	// 題名
	cout << "題名を入力" << endl;
	cin >> name;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	// 内容
	cout << "内容を入力" << endl;
	cin >> content;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	// 優先度
	cout << "優先度を入力" << endl;
	cin >> priority;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	/// 期日
	// 月
	cout << "締切(月)を入力" << endl;
	cin >> deadline.month;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	// 日
	cout << "締切(日)を入力" << endl;
	cin >> deadline.day;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	// 状態
	cout << "状態を入力" << endl;
	cout << "1:完了,0:未完了" << endl;
	cin >> state;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	// ID
	cout << "担当者のIDを入力" << endl;
	cin >> picId;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	int addId = AddTask(picId, name, content, priority, deadline, state);
	cout << "ID：" << addId << "タスク名：" << name << "を追加" << endl;
}

void TaskManager::ChangeDeadLine()
{
	int id = -1;
	Date deadline;
	// ID入力
	cout << "IDを入力" << endl;
	AllTask();
	cin >> id;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	// 期限(月)
	cout << "期限(月)を入力" << endl;
	cin >> deadline.month;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	// 期限(日)
	cout << "期限(日)を入力" << endl;
	cin >> deadline.day;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	SetDeadLine(id, deadline);
	cout << "ID：" << id << "の期限を" << " " << deadline.month << "/" << " " << deadline.day << "に変更" << endl;
}

void TaskManager::ChangeState()
{
	int id = -1;
	bool state;
	// ID入力
	cout << "IDを入力" << endl;
	AllTask();
	cin >> id;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	// 状態
	cout << "状態を入力 1:完了,0: 未完了" << endl;
	cin >> state;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	cout << "----" << endl;
	SetState(id, state);
	cout << "ID：" << id << "の状態を" << " " << state << "に変更" << endl;
}

void TaskManager::DeleteTaskSelect()
{
	int id = -1;
	// ID入力
	cout << "IDを入力" << endl;
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
    cout << "ID:" << " " << taskId << "を削除" << endl;
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
