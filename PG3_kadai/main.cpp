#include <iostream>
#include <vector>
#include <list>

#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main()
{
	IShape* ishape = new Circle();
	ishape->Size();
	ishape->Draw();

	delete ishape;

	ishape = new Rectangle();
	ishape->Size();
	ishape->Draw();

	return 0;
}