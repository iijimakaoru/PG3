#pragma once
#include "PIC.h"
#include <list>
#include <memory>

class PICManager
{
private:
	PICManager() {};
	~PICManager() {};
	// 追加
	unsigned int AddPic(std::string name, std::string className);
	// 名前変更
	void SetName(unsigned int id, std::string _name);
	// クラス名変更
	void SetClass(unsigned int id, std::string _class);
	// 削除
	void DeletePic(unsigned int id);
	// IDがない場合
	void IDerror();

public:
	PICManager(const PICManager& m) = delete;
	PICManager& operator=(const PICManager& m) = delete;
	static PICManager* GetInstance();

	// 今登録されている担当者列挙
	void AllPic();

	// 担当者の追加
	void CreatePic();

	// 名前変更
	void ChangeName();

	// クラス名変更
	void ChangeClass();

	// 担当者削除
	void DeletePicSelect();

	// ID探し
	PIC* GetPic(unsigned int id);

private:
	std::list<std::unique_ptr<PIC>> pics;
};
