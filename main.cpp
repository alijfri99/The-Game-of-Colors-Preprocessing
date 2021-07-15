#include <iostream>
#include "Color.h"

using namespace std;

int main()
{
	Color color(255, 255, 255);

	cout << color.magnitude();
}