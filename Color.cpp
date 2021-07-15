#include "Color.h"
#include<cmath>

Color::Color()
{
	this->red = 0;
	this->green = 0;
	this->blue = 0;
}

Color::Color(int red, int green, int blue)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
}

void Color::invert()
{
	this->red = 255 - this->red;
	this->green = 255 - this->green;
	this->blue = 255 - this->blue;
}

int Color::magnitude()
{
	int result = sqrt((this->red * this->red) + (this->green * this->green) + (this->blue * this->blue));
	return result;
}