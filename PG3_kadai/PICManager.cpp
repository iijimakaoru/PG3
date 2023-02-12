#include "PICManager.h"
#include <iterator>
#include <iostream>
#include <stdio.h>

using namespace std;

PICManager* PICManager::GetInstance()
{
	static PICManager instance;
	return &instance;
}

void PICManager::AllPic()
{
    cout << "���ݓo�^����Ă���S����" << endl;
    for (auto& itr : pics)
    {
        cout << "�S����ID:" << itr->GetID() << " �N���X��:" << itr->GetClass() << " �S���Җ�:" << itr->GetName() << "\n" << endl;
    }
}

void PICManager::CreatePic()
{
    string name;
    string className;
    // ���O����
    cout << "�S���Җ�����" << endl;
    cin >> name;
    if (cin.fail())
    {
        cin.clear();
    }
    cin.ignore(1024, '\n');
    cout << "----" << endl;
    // �N���X������
    cout << "�N���X������" << endl;
    cin >> className;
    if (cin.fail())
    {
        cin.clear();
    }
    cin.ignore(1024, '\n');
    cout << "----" << endl;
    int addID = AddPic(name, className);
    cout << "ID�F" << addID << "�S���ҁF" << className + name << "��ǉ�" << endl;
}

unsigned int PICManager::AddPic(std::string name, std::string className)
{
    int id = 1;
    for (unsigned int i = 0; i < pics.size(); i++)
    {
        bool success = true;
        id++;
        for (auto& itr : pics)
        {
            if (itr->GetID() == id)
            {
                success = false;
                break;
            }
        }
        if (success)
        {
            unique_ptr<PIC> newPic = make_unique<PIC>(id, name, className);
            pics.push_back(move(newPic));
            return id;
        }

    }
    if (pics.size() == 0)
    {
        int id = 1;
        unique_ptr<PIC> temp = make_unique<PIC>(id, name, className);
        pics.push_back(move(temp));
        return id;
    }
    return -1;
}

PIC* PICManager::GetPic(unsigned int id)
{
    PIC* ptr;
    for (auto& itr : pics)
    {
        if (itr->GetID() == id)
        {
            ptr = itr.get();
            return ptr;
        }
    }
    IDerror();
    return nullptr;
}

void PICManager::ChangeName()
{
    int id = -1;
    string name;
    // ID����
    cout << "ID�����" << endl;
    AllPic();
    cin >> id;
    if (cin.fail())
    {
        cin.clear();
    }
    cin.ignore(1024, '\n');
    cout << "----" << endl;
    // ���O�ύX
    cout << "���O�����" << endl;
    cin >> name;
    if (cin.fail())
    {
        cin.clear();
    }
    cin.ignore(1024, '\n');
    cout << "----" << endl;
    SetName(id, name);
    cout << "ID�F" << id << "�̒S���Җ���" << name << "�ɕύX" << endl;
}

void PICManager::SetName(unsigned int id, std::string _name)
{
    for (auto& itr : pics)
    {
        if (itr->GetID() == id)
        {
            itr->SetName(_name);
            return;
        }
    }
    IDerror();
}

void PICManager::ChangeClass()
{
    int id = -1;
    string className;
    // ID����
    cout << "ID�����" << endl;
    AllPic();
    cin >> id;
    if (cin.fail())
    {
        cin.clear();
    }
    cin.ignore(1024, '\n');
    cout << "----" << endl;
    // ���O�ύX
    cout << "�N���X�������" << endl;
    cin >> className;
    if (cin.fail())
    {
        cin.clear();
    }
    cin.ignore(1024, '\n');
    cout << "----" << endl;
    SetClass(id, className);
    cout << "ID�F" << id << "�̃N���X����" << className << "�ɕύX" << endl;
}

void PICManager::SetClass(unsigned int id, std::string _class)
{
    for (auto& itr : pics)
    {
        if (itr->GetID() == id)
        {
            itr->SetClass(_class);
            return;
        }
    }
    IDerror();
}

void PICManager::DeletePicSelect()
{
    int id = -1;
    // ID����
    cout << "ID�����" << endl;
    AllPic();
    cin >> id;
    if (cin.fail())
    {
        cin.clear();
    }
    cin.ignore(1024, '\n');
    DeletePic(id);
    cout << "----" << endl;
}

void PICManager::DeletePic(unsigned int id)
{
    pics.remove_if([=](auto& itr) {return itr->GetID() == id; });
    cout << "ID:" << " " << id << "���폜" << endl;
}

void PICManager::IDerror()
{
    cout << "�Y����Id������܂���" << endl;
}

