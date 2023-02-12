#pragma once
#include <string>

class PIC
{
private:
	// ID
	unsigned int id;
	// ����
	std::string name;
	// �N���X
	std::string className;

public:
	PIC(unsigned int _id,std::string _name, std::string _className);
	// ID�擾
	int GetID();
	// �����擾
	std::string GetName();
	// �N���X���擾
	std::string GetClass();
	// �����Z�b�g
	void SetName(std::string _name);
	// �N���X���Z�b�g
	void SetClass(std::string _className);
};
