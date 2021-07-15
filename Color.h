#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
	int red, green, blue;
	Color();
	Color(int red, int green, int blue);
	Color invert();
	int magnitude();
};

#endif