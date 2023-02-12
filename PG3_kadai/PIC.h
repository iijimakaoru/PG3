#pragma once
#include <string>

class PIC
{
private:
	// ID
	unsigned int id;
	// 氏名
	std::string name;
	// クラス
	std::string className;

public:
	PIC(unsigned int _id,std::string _name, std::string _className);
	// ID取得
	int GetID();
	// 氏名取得
	std::string GetName();
	// クラス名取得
	std::string GetClass();
	// 氏名セット
	void SetName(std::string _name);
	// クラス名セット
	void SetClass(std::string _className);
};
