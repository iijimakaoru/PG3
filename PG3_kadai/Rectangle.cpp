#include "Rectangle.h"

void Rectangle::Size()
{
	result = width * height;
}

void Rectangle::Draw()
{
	printf("��%0.1fcm�A�c%0.1fcm�̋�`�̖ʐς�%0.1fcm^2\n", width, height, result);
}
