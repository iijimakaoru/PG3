#include "Circle.h"

void Circle::Size()
{
	result = r * r * pi;
}

void Circle::Draw()
{
	printf("���a%0.1fcm�̉~�̖ʐς�%fcm^2\n", r, result);
}
