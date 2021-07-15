#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
	int red, green, blue;
	Color(int red, int green, int blue);
	void invert();
	int magnitude();
};

#endif