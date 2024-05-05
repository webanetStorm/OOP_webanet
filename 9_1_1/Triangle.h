#pragma once

#include <iostream>


class Triangle
{

private:

	int _a, _b, _c;


public:

	Triangle( int, int, int );

	int Perimetr();

	double Square();

	Triangle operator+( Triangle );

	Triangle operator-( Triangle );

	bool IsValid();

	void Print();

};
