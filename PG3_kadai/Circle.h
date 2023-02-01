#pragma once
#include"IShape.h"

class Circle : public IShape
{
private:
	float pi = 3.14159265359f;
	float r = 5;
	float result = 0;

public:
	void Size() override;
	void Draw() override;
};

