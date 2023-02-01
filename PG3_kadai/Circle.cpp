#include "Circle.h"

void Circle::Size()
{
	result = r * r * pi;
}

void Circle::Draw()
{
	printf("”¼Œa%0.1fcm‚Ì‰~‚Ì–ÊÏ‚Í%fcm^2\n", r, result);
}
