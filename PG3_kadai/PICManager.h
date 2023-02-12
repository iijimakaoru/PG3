#pragma once
#include "PIC.h"
#include <list>
#include <memory>

class PICManager
{
private:
	PICManager() {};
	~PICManager() {};
	// �ǉ�
	unsigned int AddPic(std::string name, std::string className);
	// ���O�ύX
	void SetName(unsigned int id, std::string _name);
	// �N���X���ύX
	void SetClass(unsigned int id, std::string _class);
	// �폜
	void DeletePic(unsigned int id);
	// ID���Ȃ��ꍇ
	void IDerror();

public:
	PICManager(const PICManager& m) = delete;
	PICManager& operator=(const PICManager& m) = delete;
	static PICManager* GetInstance();

	// ���o�^����Ă���S���җ�
	void AllPic();

	// �S���҂̒ǉ�
	void CreatePic();

	// ���O�ύX
	void ChangeName();

	// �N���X���ύX
	void ChangeClass();

	// �S���ҍ폜
	void DeletePicSelect();

	// ID�T��
	PIC* GetPic(unsigned int id);

private:
	std::list<std::unique_ptr<PIC>> pics;
};
