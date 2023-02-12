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

		// ���ݓo�^����Ă�����
		picMan->AllPic();
		taskMan->AllTask();
		cout << "----" << endl;

		// �S����or�^�X�N
		cout << "1:�S���ґ���" << "\n" << "2:�^�X�N����" << "\n" << endl;
		cin >> select;
		if (select == 1)
		{
			cout << "1:�S���Ғǉ�,2:���O�ύX,3:�N���X�ύX,���̑�:�S���ҍ폜" << "\n" << endl;
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
			cout << "1:�^�X�N�쐬,2:���ؓ��ύX,3:��ԕύX,4:�^�X�N�̍폜" << endl;
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