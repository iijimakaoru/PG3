#include <iostream>
#include <vector>
#include <list>

#include "TaskManager.h"
#include "PICManager.h"

using namespace std;

int main()
{
	PICManager* picMan = PICManager::GetInstance();
	TaskManager* taskMan = TaskManager::GetInstance();

	while (true)
	{
		int select = -1;

		// 現在登録されているやつ
		picMan->AllPic();
		taskMan->AllTask();
		cout << "----" << endl;

		// 担当者orタスク
		cout << "1:担当者操作" << "\n" << "2:タスク操作" << "\n" << endl;
		cin >> select;
		if (select == 1)
		{
			cout << "1:担当者追加,2:名前変更,3:クラス変更,その他:担当者削除" << "\n" << endl;
			cin >> select;
			if (select == 1)
			{
				picMan->CreatePic();
			}
			else if (select == 2)
			{
				picMan->ChangeName();
			}
			else if (select == 3)
			{
				picMan->ChangeClass();
			}
			else
			{
				picMan->DeletePicSelect();
			}
		}
		else if (select == 2)
		{
			cout << "1:タスク作成,2:締切日変更,3:状態変更,4:タスクの削除" << endl;
			cin >> select;
			if (select == 1)
			{
				taskMan->CreateTask();
			}
			else if (select == 2)
			{
				taskMan->ChangeDeadLine();
			}
			else if (select == 3)
			{
				taskMan->ChangeState();
			}
			else
			{
				taskMan->DeleteTaskSelect();
			}
		}

		cout << "========" << "\n" << endl;
	}

	system("pause");

	return 0;
}