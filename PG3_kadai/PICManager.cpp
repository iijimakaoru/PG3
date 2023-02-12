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
    cout << "現在登録されている担当者" << endl;
    for (auto& itr : pics)
    {
        cout << "担当者ID:" << itr->GetID() << " クラス名:" << itr->GetClass() << " 担当者名:" << itr->GetName() << "\n" << endl;
    }
}

void PICManager::CreatePic()
{
    string name;
    string className;
    // 名前入力
    cout << "担当者名入力" << endl;
    cin >> name;
    if (cin.fail())
    {
        cin.clear();
    }
    cin.ignore(1024, '\n');
    cout << "----" << endl;
    // クラス名入力
    cout << "クラス名入力" << endl;
    cin >> className;
    if (cin.fail())
    {
        cin.clear();
    }
    cin.ignore(1024, '\n');
    cout << "----" << endl;
    int addID = AddPic(name, className);
    cout << "ID：" << addID << "担当者：" << className + name << "を追加" << endl;
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
    // ID入力
    cout << "IDを入力" << endl;
    AllPic();
    cin >> id;
    if (cin.fail())
    {
        cin.clear();
    }
    cin.ignore(1024, '\n');
    cout << "----" << endl;
    // 名前変更
    cout << "名前を入力" << endl;
    cin >> name;
    if (cin.fail())
    {
        cin.clear();
    }
    cin.ignore(1024, '\n');
    cout << "----" << endl;
    SetName(id, name);
    cout << "ID：" << id << "の担当者名を" << name << "に変更" << endl;
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
    // ID入力
    cout << "IDを入力" << endl;
    AllPic();
    cin >> id;
    if (cin.fail())
    {
        cin.clear();
    }
    cin.ignore(1024, '\n');
    cout << "----" << endl;
    // 名前変更
    cout << "クラス名を入力" << endl;
    cin >> className;
    if (cin.fail())
    {
        cin.clear();
    }
    cin.ignore(1024, '\n');
    cout << "----" << endl;
    SetClass(id, className);
    cout << "ID：" << id << "のクラス名を" << className << "に変更" << endl;
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
    // ID入力
    cout << "IDを入力" << endl;
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
    cout << "ID:" << " " << id << "を削除" << endl;
}

void PICManager::IDerror()
{
    cout << "該当のIdがありません" << endl;
}

