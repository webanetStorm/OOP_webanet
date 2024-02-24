#include "Triangle.h"
#include <math.h>


Triangle::Triangle( int a, int b, int c )
{
	_a = a;
	_b = b;
	_c = c;
}

int Triangle::Perimetr()
{
	return _a + _b + _c;
}

double Triangle::Square()
{
	double p = Perimetr() / 2.0;

	return sqrt( p * ( p - _a ) * ( p - _b ) * ( p - _c ) );
}
