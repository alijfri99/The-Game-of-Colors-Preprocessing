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

Color Color::invert()
{
	Color inversion(255 - this->red, 255 - this->green, 255 - this->blue);
	return inversion;
}

int Color::magnitude()
{
	int result = sqrt((this->red * this->red) + (this->green * this->green) + (this->blue * this->blue));
	return result;
}

bool Color::operator < (Color c)
{
	return this->magnitude() < c.magnitude();
}