#include "PIC.h"

PIC::PIC(unsigned int _id,std::string _name, std::string _className)
{
	// ID
	id = _id;
	// ���O
	name = _name;
	// �N���X��
	className = _className;
}

int PIC::GetID() { return id; }

std::string PIC::GetName() { return name; }

std::string PIC::GetClass() { return className; }

void PIC::SetName(std::string _name) { name = _name; }

void PIC::SetClass(std::string _className) { className = _className; }
