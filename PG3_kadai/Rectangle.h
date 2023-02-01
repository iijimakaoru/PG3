#pragma once
#include "IShape.h"

class Rectangle : public IShape
{
private:
	float width = 5;
	float height = 10;
	float result = 0;

public:
	void Size()override;
	void Draw()override;
};

